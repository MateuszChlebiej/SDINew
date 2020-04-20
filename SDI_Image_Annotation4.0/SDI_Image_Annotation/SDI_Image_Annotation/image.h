#ifndef IMAGE_H
#define IMAGE_H

#include <QObject>

class Image : public QObject
{
    Q_OBJECT
public:

    explicit Image(QObject *parent = nullptr);
    //Overload Constructer

    /*!
     * \brief load_image_into_canvas
     * NOT IMPLEMENTED
     */
    void load_image_into_canvas();


    /*!
     * \brief set_image_name
     * Sets image_name attribute, takes QString as argument.
     */
    void set_image_name(QString);

    /*!
     * \brief set_image_path
     * Sets image_path attribute(used when the images directory is needed, takes QString as argument.
     */
    void set_image_path(QString);

    /*!
     * \brief get_image_name
     * Retrieves the image_name attribute of the Image object.
     * \return image_name as QString
     */
    QString get_image_name();

    /*!
     * \brief get_image_path
     * Retrieves the image_path attribute of the Image object.
     * \return image_path as QString
     */
    QString get_image_path();






private:
    /*!
     * \brief image_name
     * QString Attribute storing Object name.
     */
    QString image_name;
    /*!
     * \brief image_path
     * QString Attribute storing Object path.
     */
    QString image_path;
    /*!
     * \brief is_loaded
     * Boolean used to determine if image is currently loaded into canvas or not.
     * NOT IMPLEMENTED
     */
    bool is_loaded;



signals:

};

#endif // IMAGE_H
