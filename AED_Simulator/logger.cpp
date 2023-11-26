#include "logger.h"

Logger::Logger(){
    dateHandler = new QDateTime();
    setup();
}

//TO-DO: Make setup test button and log test button
void Logger::setup(){
    QString currentDate = dateHandler->currentDateTime().toString("yyyy:MM:dd") + "-AED";
    QString dirPath = QString(LOG_PATH) + "/" + currentDate;

        if (!QDir(dirPath).exists()) {
            QDir().mkpath(dirPath);
        }

        QString activeFileName = dirPath + "/" + dateHandler->currentDateTime().toString("yyyy:MM:dd hh:mm:ss") + "-AED_LOG.log";
        activeFile = new QFile(activeFileName);
        outStream.setDevice(activeFile);
        if (activeFile->open(QIODevice::WriteOnly | QIODevice::Text)) {
            log("File Opened Successfully\n");
        } else {
            qInfo() << "Could Not Open Log File" << Qt::endl;
        }

        // Set this file as this runtime's file to write to [activeFile]
}

void Logger::log(string message){
    if(!activeFile || !activeFile->isOpen()){
        qInfo() << "Could Not Load Log File" << Qt::endl;
        return;
    }
    QString prefix = dateHandler->currentDateTime().toString("yyyy:MM:dd hh:dd:ss") + " ===> ";
    QString qMessage = prefix + QString::fromStdString(message);

    outStream << qMessage << Qt::endl;

}

void Logger::cleanup(){
    if (activeFile != nullptr && activeFile->isOpen()) {
        activeFile->close();
        delete activeFile;
        activeFile = nullptr; // Set to nullptr to avoid accessing a deleted pointer
    }
}

Logger::~Logger(){
    cleanup();
    delete dateHandler;
}