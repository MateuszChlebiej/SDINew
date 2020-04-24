#ifndef NODE_H
#define NODE_H
#include <QString>
#include "QVector"


class Node
{
public:

    Node *next; //Pointer to next


    QString imageName; //data
    QString imagePath;
    QString lastMod;

private:


};

#endif // NODE_H
