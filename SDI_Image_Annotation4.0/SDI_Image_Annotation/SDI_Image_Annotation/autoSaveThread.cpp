#include <qdebug.h>
#include<qtimer.h>
#include"autoSaveThread.h"
#include "mainwindow.h"
#include "qmainwindow.h"

void AutoSaveThread::run(){

    while(true){
        //sleep for X amount of time then autosave
        std::this_thread::sleep_for(std::chrono::seconds(saveTimer));
        //MainWindow::saveAnnotationFile("AutoSave");
    }

}

