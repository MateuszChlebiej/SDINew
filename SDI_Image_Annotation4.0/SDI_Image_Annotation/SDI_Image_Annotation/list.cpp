#include <qmessagebox.h>
#include "list.h"
#include "node.h"
#include "image.h"
#include "QDebug"


using namespace std;

bool List::IsEmpty(){

    return head == nullptr;
}
//Insert node for class
Node* List::InsertNodeClass(int index, QString name){
    if (index <0){
        return NULL;
    }

    int currindex = 1;
    Node* currNode = head;
    while(currNode && index > currindex){
        currNode = currNode-> next;
        currindex ++;
    }

    if(index>0 && currNode == NULL){
        return NULL;
    }
    Node* newNode = new Node;
    newNode->imageName = name;
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

//Insert new node with extra data for image, path and last modified
Node* List::InsertNodeImage(int index, QString name,QString path,QString lastModified){
    if (index <0){
        return NULL;
    }

    int currindex = 1;
    Node* currNode = head;
    while(currNode && index > currindex){
        currNode = currNode-> next;
        currindex ++;
    }

    if(index>0 && currNode == NULL){
        return NULL;
    }
    Node* newNode = new Node;
    newNode->imageName = name;
    newNode->imagePath = path;
    newNode->lastMod = lastModified;
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



//Find Node by name return index
int List::FindNodeGiveIndex(QString x){
    Node* currNode = head;
    int currIndex = 1;
    while(currNode && currNode -> imageName != x){
        currNode = currNode -> next;
        currIndex ++;
        qDebug() << "NoItem";
    }
    if (currNode){
        qDebug() << currNode ->imageName;
        qDebug() << currIndex;
        return currIndex;
    }
    return 0;
}
//Find node by name return path
QString List::FindNodeGivePath(QString x){
    Node* currNode = head;
    int currIndex = 1;
    while(currNode && currNode -> imageName != x){
        currNode = currNode -> next;
        currIndex ++;
        qDebug() << "NoItem";
    }
    if (currNode){

        return currNode->imagePath;
    }
    return 0;
}

//Delete node with given name
int List::DeleteNode(QString x){
    Node* prevNode = nullptr;
    Node* currNode = head;
    int currIndex = 1;
    while(currNode && currNode->imageName != x){
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
}

//Get name list of all items in list
void List::GetNameList(void){
    QStringList namesList;
    namesList.clear();
    Node* currNode = head;
    while (currNode != NULL){
        namesList.append(currNode->imageName);
        currNode = currNode -> next;
    }

   name_List = namesList;
}

//Get all values for modified and image names, sort by modified date
QStringList List::GetModifiedList(QString sortType){
    vector<QPair<QString,int>> list;
    QStringList namesList;
    Node* currNode = head;
    while (currNode != NULL){
       QString image_name = currNode->imageName;
       QString last_mod = currNode->lastMod;
       //Use Q pairs of name and last modified
       list.push_back(QPair<QString,int>(image_name,last_mod.toInt()));
       currNode = currNode -> next;
    }
    if(sortType == "Ascending"){
        sort(list.begin(), list.end(), [](const QPair<QString, int> &x,
                                               const QPair<QString, int> &y)
        {
            return x.second < y.second;
        });

    }
    if(sortType == "Descending"){
        sort(list.begin(), list.end(), [](const QPair<QString, int> &x,
                                               const QPair<QString, int> &y)
        {
            return x.second > y.second;
        });
    }

    for(auto item:list){
        namesList.append(item.first);
    }
    //Return list of names sorted, can be used for ui element.
    return namesList;
}
//Count number of items in list.
int List::CountItems(void){
    int num = 0;
    Node* currNode = head;
    while (currNode != NULL){
        currNode = currNode -> next;
        num ++;
    }

    return num;
}

//List destructor.
List::~List(void){
    Node* currNode = head, *nextNode = NULL;
    while(currNode != NULL){
        nextNode = currNode->next;
        //DestroyNode
        delete currNode;
        currNode = nextNode;
    }
}
