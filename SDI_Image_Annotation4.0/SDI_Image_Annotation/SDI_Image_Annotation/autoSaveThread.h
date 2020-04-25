#ifndef AUTOSAVETHREAD_H
#define AUTOSAVETHREAD_H

#endif // AUTOSAVETHREAD_H
#include <QThread>
#pragma once
class AutoSaveThread : public QThread {
    Q_OBJECT
public:

protected:
    /*!
     * \brief run
     * called when thread starts, defines functioning of auto save thread
     * \param
     */
    void run();
private:
    /*!
     * \brief save timer
     *time between autosaves
     */
    int saveTimer = 10;
};
