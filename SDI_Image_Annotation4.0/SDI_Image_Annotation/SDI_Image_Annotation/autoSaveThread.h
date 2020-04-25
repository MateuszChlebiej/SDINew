#ifndef AUTOSAVETHREAD_H
#define AUTOSAVETHREAD_H

#endif // AUTOSAVETHREAD_H
#include <QThread>
#pragma once
class AutoSaveThread : public QThread {
    Q_OBJECT
public:
    bool active;
protected:
    void run();
private:
    int saveTimer = 10;
};
