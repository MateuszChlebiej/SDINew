#include"autoSaveThread.h"
#include <qdebug.h>
#include<qtimer.h>
void AutoSaveThread::run(){
    active = true;
    QTimer timer;
    timer.setSingleShot(true);
    timer.start(60000);
//    while (active) {
//        //std::this_thread::sleep_for(std::chrono::seconds(saveTimer));
//        // save annotations file
//        if(!timer.isActive()){
//            //put save code here...
//        qDebug() << "autosaved";

//        timer.start(1000);
//        }
      while(true){
          std::this_thread::sleep_for(std::chrono::seconds(saveTimer));
           qDebug() << "autosaved";
      }
//    if(!active){
//        this->quit();
//        this->wait();
//    }
}
