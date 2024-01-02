#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTime>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>
#include <QStandardPaths>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::on_pushButton_clicked()
{
    // Set the file path to C:/Users/tahau/Documents
    QString selectedPath = "C:/Users/tahau/Documents";

    // Get the current date and time
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString dateTimeString = currentDateTime.toString("yyyyMMdd_hhmmss");

    // Get the message text from the user UI (assuming a QPlainTextEdit named "plainTextEdit")
    QString messageText = ui->plainTextEdit->toPlainText();

    // Create the filename with the current date and time
    QString filename = selectedPath + "/message_" + dateTimeString + ".txt"; // Use "/" for cross-platform compatibility

    // Open the file for writing
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        // Write the message to the file
        QTextStream stream(&file);
        stream << messageText;
        file.close();

        // Notify the user about successful saving
        QMessageBox::information(this, "File Saved", "Message saved successfully to " + filename);
    } else {
        // Handle file opening errors
        QMessageBox::warning(this, "Error Saving File", "Failed to save message to file: " + file.errorString());
    }
}
