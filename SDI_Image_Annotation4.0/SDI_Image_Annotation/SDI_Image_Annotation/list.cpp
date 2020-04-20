#include "list.h"
#include "node.h"
#include "image.h"
#include <qmessagebox.h>
#include "QDebug"


bool List::IsEmpty(){

    return head == nullptr;
}

Node* List::InsertNode(int index, QString name,QString path){
    if (index <0){
        return nullptr;
    }

    int currindex = 1;
    Node* currNode = head;
    while(currNode && index > currindex){
        currNode = currNode-> next;
        currindex ++;
    }

    if(index>0 && currNode == nullptr){
        return nullptr;
    }
    Node* newNode = new Node;
    newNode->imageName = name;
    newNode->imagePath = path;
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



/*int List::FindNode(double x){
    Node* currNode = head;
    int currIndex = 1;
    while(currNode && currNode -> data != x){
        currNode = currNode -> next;
        currIndex ++;
    }
    if (currNode){
        return currIndex;
    }
    return 0;
}

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

void List::DisplayList(void){
    int num = 0;
    Node* currNode = head;
    while (currNode != nullptr){
        qDebug()<<currNode->imageName<<currNode->imagePath;
        currNode = currNode -> next;
        num ++;
    }
}
