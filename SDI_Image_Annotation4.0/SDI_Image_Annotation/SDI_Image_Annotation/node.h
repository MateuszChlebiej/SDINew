#ifndef NODE_H
#define NODE_H
#include <QString>
#include "QVector"

/*!
 * \brief The Node class
 * Node class used for node creation within linked lists.
 */
class Node
{
public:
    /*!
     * \brief next
     * Pointer to next node in the list.
     */
    Node *next; //Pointer to next

    /*!
     * \brief imageName, imagePath, lastMod
     * Data of the node
     */
    QString imageName; //data
    QString imagePath;
    QString lastMod;

private:


};

#endif // NODE_H
