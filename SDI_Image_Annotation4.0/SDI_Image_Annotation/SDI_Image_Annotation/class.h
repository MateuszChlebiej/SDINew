#ifndef CLASS_H
#define CLASS_H

#include <QString>
#include <QMainWindow>


class Class
{
private:
    Class* head;
    Class* next;
    QStringList Data;
    QVector<QString> data;
    QString Name;

public:
    Class();
    ~Class();

    bool IsEmpty();
    Class* InsertNode(int index, QVector<QString> _data);
    int FindNode(QString _name);
    QVector<QString> FetchData(QString _name);
    int DeleteFromList(double x);
    void DisplayList(void);

};

#endif // CLASS_H
