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


    bool IsEmpty();
    Node* InsertNode(int index, QString,QString);
    int FindNode(double x);
    int DeleteNode(double x);
    void DisplayList(void);

};

#endif // LIST_H
