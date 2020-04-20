#ifndef ANNOTATIONCLASS_H
#define ANNOTATIONCLASS_H

#include <QObject>

class AnnotationClass : public QObject
{
    Q_OBJECT
public:
    explicit AnnotationClass(QObject *parent = nullptr);

    /*!
     * \brief set_name_and_line
     *
     * Sets the class name and line number from within the file.
     */
    void set_name_and_line(QString,int);

    /*!
     * \brief get_name
     * Retrieves the name of the object for use within other functions.
     * \return class_name as Qstring
     */
    QString get_name();
    /*!
     * \brief get_line_number
     * Retrieves the line number of specific object when within file.
     * \return class_line_number as integer.
     */
    int get_line_number();


private:
    /*!
     * \brief class_name
     * Store name of class as QString.
     */
    QString class_name;
    /*!
     * \brief class_line_number
     * Store file line number as integer.
     */
    int class_line_number;


signals:

};

#endif // ANNOTATIONCLASS_H
