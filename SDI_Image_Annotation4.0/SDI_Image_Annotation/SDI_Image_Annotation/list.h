#ifndef LIST_H
#define LIST_H
#include "image.h"
#include "node.h"

class List
{
private:
    double data;
    Node * next;
    Node *head;
public:

    List(void){head=NULL;}
    ~List(void);
    QStringList name_List;

    bool IsEmpty();
    Node* InsertNodeClass(int index, QString);
    Node* InsertNodeImage(int index, QString,QString,QString);
    int FindNodeGiveIndex(QString x);
    QString FindNodeGivePath(QString x);
    int DeleteNode(QString x);
    int DeleteList();
    void DisplayList(void);
    void GetNameList(void);

    QStringList GetModifiedList(QString);
    int CountItems(void);
};

#endif // LIST_H
