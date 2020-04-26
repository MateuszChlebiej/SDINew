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
     * Function responsible for inserting a new node into the class Linked List
     * \param index
     * Position of node within the list.
     * \param name
     * Name of the class
     * \return
     * Returns the new node
     */
    Node* InsertNodeClass(int index, QString name);
    /*!
     * \brief InsertNodeImage
     * Function responsible for inserting a new node into the images Linked List.
     * \param index
     * Position of node within the list.
     * \param name
     * Image name
     * \param path
     * Image path
     * \param lastModified
     * Images last modified date
     * \return
     */
    Node* InsertNodeImage(int index, QString name ,QString path ,QString lastModified);
    /*!
     * \brief FindNodeGiveIndex
     * Dunction used to find specific node based on name of image or class.
     * \param x
     * QString which is the name of class or image the person wants to find.
     * \return
     * Return the index of the node
     */
    int FindNodeGiveIndex(QString x);
    /*!
     * \brief FindNodeGivePath
     * Function to find node from list by name.
     * \param x
     * Name of image to search for.
     * \return
     * Return path of image
     */
    QString FindNodeGivePath(QString x);
    /*!
     * \brief DeleteNode
     * Function to delete node with specific name from list.
     * \param x
     * Name of node to delete
     * \return
     * Return index of deleted node
     */
    int DeleteNode(QString x);
    /*!
     * \brief DisplayList
     * Function to display the contents of entire list.
     */
    void DisplayList(void);
    /*!
     * \brief GetNameList
     * Function responsible for updating the name_List variable with names of all images/classes in list.
     */
    void GetNameList(void);
    /*!
     * \brief GetModifiedList
     * Function responsible for getting all Last modified data from list, sorting the data by ascending or descending.
     * \return
     * Return QStringList with image names sorted by modified list ready to be pushed ot the ui.
     */
    QStringList GetModifiedList(QString);
    /*!
     * \brief CountItems
     * Function to count the amount of items in a list
     * \return
     * Return Integer value for items in list.
     */
    int CountItems(void);
};

#endif // LIST_H
