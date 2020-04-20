#include "class.h"

#include <QString>
#include <QDebug>

Class::Class()
{
 head = nullptr;
}
bool Class::IsEmpty(){

    return head == nullptr;
}

Class* Class::InsertNode(int index, QString _name,QString _colour){
    if (index <0){
        return nullptr;
    }
    int currindex = 1;
    Class* currNode = head;
    while(currNode && index > currindex){
        currNode = currNode-> next;
        currindex ++;
    }

    if(index>0 && currNode == nullptr){
        return nullptr;
    }
    Class* newNode = new Class;

    newNode ->data = _name;

    if(index == 0){
        newNode-> next = head;
        head = newNode;
    }
    else{
        newNode-> next = currNode-> next;
        currNode-> next = newNode;
    }
    return newNode;

}


int Class::FindNode(QString _name){
    Class* currNode = head;
    int currIndex = 1;
    while(currNode && currNode->Name != _name ){
        currNode = currNode -> next;
        currIndex ++;
    }
    if (currNode){
        return currIndex;
    }
    return 0;
}

/*
int List::DeleteNode(double x){
    Node* prevNode = nullptr;
    Node* currNode = head;
    int currIndex = 1;
    while(currNode && currNode->data != x){
        prevNode = currNode;
        currNode = currNode -> next;
        currIndex++;
    }
    if(currNode){
        if(prevNode){
            prevNode -> next = currNode -> next;
            delete currNode;
        }
        else{
            head = currNode -> next;
            delete currNode;
        }
        return currIndex;
    }
    return 0;
}*/

void Class::DisplayList(void){
    int num = 0;
    Class* currNode = head;
    while (currNode != nullptr){
        qDebug()<<"Heres the list";
        qDebug()<<currNode->data;
        currNode = currNode -> next;
        num ++;
    }
}
