#ifndef LIST_H
#define LIST_H
#include "image.h"
#include "node.h"

/*!
 * \brief The List class
 * List Class is responsible for the linked lists within the project, each object of the class is a linked list capable of storing information, these are used for storing information about classes and images.
*/
class List
{
private:
    /*!
     * \brief data
     * Private variable for storing the data part of the list.
     */
    double data;
    /*!
     * \brief next
     * Instance of node pointing to the next node of the list.
     */
    Node * next;
    /*!
     * \brief head
     * Instance of node pointing to the head of the list.
     */
    Node *head;
public:
    /*!
     * \brief List , ~List
     * List constructor and destructor
     */
    List(void){head=NULL;}
    ~List(void);

    /*!
     * \brief name_List
     * QStringList storing names of each image/class in the list.
     */
    QStringList name_List;

    /*!
     * \brief IsEmpty
     * Check for empty List
     * \return
     * Returns True or false
     */
    bool IsEmpty();
    /*!
     * \brief InsertNodeClass
     * Function responsible fo rinserting a new node into the class Linked List
     * \param index
     * Position of node within the list.
     * \param name
     * Name of the class
     * \return
     * Returns the new node
     */
    Node* InsertNodeClass(int index, QString name);
    Node* InsertNodeImage(int index, QString name ,QString path ,QString lastModified);
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
