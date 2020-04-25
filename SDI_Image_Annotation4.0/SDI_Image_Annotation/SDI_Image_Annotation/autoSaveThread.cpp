#include"autoSaveThread.h"
#include <qdebug.h>
#include<qtimer.h>
void AutoSaveThread::run(){

    while(true){
        //sleep for X amount of time then autosave
        std::this_thread::sleep_for(std::chrono::seconds(saveTimer));
         qDebug() << "autosaved";
    }

}
