#include <QApplication>
#include "qdebug.h"
#include "mainwindow.h"
#include "autoSaveThread.h"



void main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    AutoSaveThread as;
    //move to different thread
    as.moveToThread(&as);
    //connect autosave signal and slot
    QObject::connect(& as, SIGNAL(triggerAutosave()), & w , SLOT(beginAutoSave()));
    w.show();
    as.start();
    qDebug() << "test 1";
    a.exec();
    qDebug() << "test 2";
    as.terminate();
}
