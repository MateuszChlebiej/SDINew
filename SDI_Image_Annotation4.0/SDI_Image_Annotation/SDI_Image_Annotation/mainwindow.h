#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QListWidget>
#include <QMainWindow>
#include <QMessageBox>
#include <QDateTime>
#include <qfile.h>
#include <qfiledialog.h>
#include <QTextStream>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include "ui_mainwindow.h"
#include "image.h"
#include "canvas.h"
#include "addclasswindow.h"
#include "class.h"
#include "list.h"
#include "autoSaveThread.h"
#pragma once
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    AddClassWindow* addclasswindow;

    QString classFile;

    Canvas canvas;

    bool annotationFileLoaded;

    QString annotationFileLoadedPath;

    /*!
         * \brief shape index
         * shape index that is sent to canvas
         */
    static int shapeIndex;

    void saveAnnotationFile(QString mode){

        QString file;

        QJsonObject document;
        QJsonArray documentArray;


        for(int i = 0; i < ui->canvas->imageList.size(); i++){

            documentArray.append(dataSaveHelp(i));

        }
        document.insert("Amount of images",ui->canvas->imageList.size());
        document.insert("Images",documentArray);


    QString json_filter = "JSON (*.json)";

    if(mode == "Manual Save"){
         file = QFileDialog::getSaveFileName(this,tr("Save File"),"/",json_filter);
    }

    if(mode == "AutoSave"){
        file = annotationFileLoadedPath;
    }

    if(file.isEmpty()){

    }
    else{

        QJsonDocument doc(document);
        qDebug() << doc.toJson();


        QByteArray data_json = doc.toJson();
        QFile output(file);
        if(output.open(QIODevice::WriteOnly | QIODevice::Text)){
            output.write(data_json);
            output.close();
            QMessageBox::information(this,tr("Message"),tr("Document saved"));
        }
        else{
            QMessageBox::critical(this,tr("Error"),output.errorString());
        }
    }
}

    QJsonArray dataSaveHelp(int imageIndex){

    QJsonArray imagesJsonArray;
    QJsonObject imageHoldObject;
    QJsonObject imagesJsonObject;
    QJsonArray shapeJsonArray;
    QJsonObject shapeJsonObject;
    QJsonArray coorJsonArray;
    QJsonObject coorJsonObject;
    QJsonObject pointJsonObject;

    for(int i = 0; i < ui->canvas->imageList[imageIndex].polygonList.size(); i++){

        int numOfPoints = ui->canvas->imageList[imageIndex].polygonList[i].shape.size();

        for(int j = 0; j < numOfPoints; j++){

            pointJsonObject.insert("X",ui->canvas->imageList[imageIndex].polygonList[i].shape[j].x());
            pointJsonObject.insert("Y",ui->canvas->imageList[imageIndex].polygonList[i].shape[j].y());
            coorJsonArray.append(pointJsonObject);
        }

        coorJsonObject.insert("Amout of points",numOfPoints);
        coorJsonObject.insert("Shape Type",ui->canvas->imageList[imageIndex].polygonList[i].shapeName);
        coorJsonObject.insert("Shape Class",ui->canvas->imageList[imageIndex].polygonList[i].className);
        coorJsonObject.insert("Points",coorJsonArray);
        for(int y = 0; y < numOfPoints; y++){
            coorJsonArray.removeFirst();
        }
        shapeJsonArray.append(coorJsonObject);

    }
    imagesJsonObject.insert("Image name",ui->canvas->imageList[imageIndex].fileName);
    imagesJsonObject.insert("Shapes",shapeJsonArray);
    imagesJsonArray.append(imagesJsonObject);

    return imagesJsonArray;
}

private slots:

    void update_class_list_and_file_add(QString newClass){

        QString addClass = newClass + "\n";

        const char *converted = addClass.toLatin1().data();

        QFile f(MainWindow::classFile);
        if (f.open(QIODevice::WriteOnly | QIODevice::Append)) {
            f.write(converted);
            f.close();
            ui->class_List->addItem(newClass);
            classes_list.InsertNodeClass(classes_list.CountItems(),newClass);
            classes_list.GetNameList();
            qDebug()<<classes_list.name_List;

        }
        if (!f.open(QFile::ReadOnly | QFile::Text)){
            QMessageBox::warning(this,"No file","You have to open a class file before adding new classes.");
        }

    }

    void update_class_list_and_file_delete(QString deletedClass){

        QFile f(MainWindow::classFile);
        if(f.open(QIODevice::ReadWrite | QIODevice::Text)){
            QString s;
            QTextStream t(&f);
            while(!t.atEnd())
            {
                QString line = t.readLine();
                if(!line.contains(deletedClass))
                    s.append(line + "\n");
            }
            f.resize(0);
            t << s;
            f.close();
        }
        classes_list.DeleteNode(deletedClass);
        classes_list.GetNameList();
        ui->class_List->clear();
        ui->class_List->addItems(classes_list.name_List);

    }

    QStringList sortingName(QStringList item_list, QString ascending_or_descending){

        int size;
        size = item_list.count();
        for(int i = 0; i < size; i++){
            for(int j = 0; j<size-1; j++){

                if(ascending_or_descending == ">"){
                    if(item_list[j] > item_list[j + 1]){
                        QString tmp;
                        tmp = item_list[j];
                        item_list[j] = item_list[j+1];
                        item_list[j + 1] = tmp;
                    }
                }
                if(ascending_or_descending == "<"){
                    if(item_list[j] < item_list[j + 1]){
                        QString tmp;
                        tmp = item_list[j];
                        item_list[j] = item_list[j + 1];
                        item_list[j + 1] = tmp;
                    }
                }
            }
        }
        return item_list;
    }

    void sortImageNames(int index){

        QStringList sorted_images;
        switch(index){
            case 0:
                ui->image_List->clear();
                sorted_images = sortingName(images_list.name_List, ">");
                ui->image_List->addItems(sorted_images);

            break;

            case 1:
                ui->image_List->clear();
                sorted_images = sortingName(images_list.name_List, "<");
                ui->image_List->addItems(sorted_images);

            break;

            case 2:
                ui->image_List->clear();
                sorted_images = images_list.GetModifiedList("Ascending");
                ui->image_List->addItems(sorted_images);
            break;

            case 3:
                ui->image_List->clear();
                sorted_images = images_list.GetModifiedList("Descending");
                ui->image_List->addItems(sorted_images);
            break;
        }
    }

    void sortClassNames(int index){

        QStringList sorted_classes;
        switch(index){
            case 0:

                ui->class_List->clear();
                //qDebug()<<classes_list.name_List;
                sorted_classes = sortingName(classes_list.name_List,">");
                //qDebug()<<sorted_classes;
                ui->class_List->addItems(sorted_classes);

            break;

            case 1:
                ui->class_List->clear();
                sorted_classes = sortingName(classes_list.name_List,"<");
                //qDebug()<<sorted_classes;
                ui->class_List->addItems(sorted_classes);
                //qDebug()<<classes_list.name_List;
            break;
        }
    }

    void imageListCurrentTextChange(QString currentText){

        for(int i = 0 ; i < ui->canvas->imageList.size(); i++){
                if(operator==(ui->canvas->currentImage.filePath,ui->canvas->imageList[i].filePath)){
                    ui->canvas->imageList.replace(i,ui->canvas->currentImage);
                }
            }


            if(currentText == ""){
                //qDebug() << "NoItem";
            }
            else{

                QString filepath = images_list.FindNodeGivePath(currentText);
                //qDebug()<<filepath;
                //qDebug()<<ui->canvas->imageList.size();


                for(Image image: ui->canvas->imageList){
                    if(operator==(filepath,image.filePath)){

                        ui->canvas->currentImage = image;
                        //qDebug() << "image loaded with " << ui->canvas->currentImage.polygonList.size() << " shapes";
                        //qDebug() << "current poly has " << ui->canvas->currentImage.currentPolygon.size() << "corners";
                        break;
                    }
                }

                ui->canvas->currentImage.fileName = currentText;
                QImage LoadedImg(filepath);
                ui->canvas->currentImage.image = LoadedImg;

                //Send corresponding image to canvas.

                ui->canvas->setPixmap(QPixmap::fromImage(canvas.currentImage.image));
                //set canvas image to current image


                //qDebug()<<ui->canvas->imageList.size();
            }
    }

    void readClassFile(){
        QString filter = "Class File (*.names)";

        ui->class_List->clear();
        QString file_name = QFileDialog::getOpenFileName(this,"Open class file","C:/Users/mateu/Desktop",filter);
        classFile = file_name;
        QFile file(classFile);
        //Track line number within file
        int line_number=0;

        if (!file.open(QFile::ReadOnly | QFile::Text)){
            QMessageBox::warning(this,"title","file not open");
            ui->class_List->clear();
        }

        QTextStream in(&file);
        while(!in.atEnd()){

            //Each line = different class/
            QString class_name = in.readLine();

            //Display items in class_List.
            ui->class_List->addItem(class_name);

            //Add class to the Class List

            classes_list.InsertNodeClass(line_number,class_name);

            line_number ++;


        file.close();

        classes_list.GetNameList();
        qDebug()<<classes_list.name_List;
        ui->folder_Path_Class->setText(file.fileName());
       }
    }

    void readImagesDirectory(){
        int lineNum = 0;

        QStringList arr_image_names;
        QString folder_name = QFileDialog::getExistingDirectory(this, ("Select Output Folder"),"C:/Users/mateu/Desktop");
        QDir dir_2(folder_name);

        //Look at each file within directory
        foreach(QFileInfo var, dir_2.entryInfoList()){
            //If file suffix == jpg or png
            if ((var.suffix() == "jpg") || (var.suffix() == "png")){
                //Store image data in Vectors


                QString lastMod = var.lastModified().toString("yyyy.dd.MM");
                lastMod.remove(".");

                //Pass image name into UI to be displayed
                ui->image_List->addItem(var.baseName());
                //Add to list with image names used for sorting.

                QImage image = QImage(var.filePath());
                images_list.InsertNodeImage(lineNum,var.baseName(),var.filePath(),lastMod);
                ui->canvas->imageList.append(Image(image,var.baseName(),var.filePath()));

                lineNum++;
            }

       }
        images_list.GetNameList();
        //Change gui label showing path of current directory.
        ui->folder_Path_Image->setText(folder_name);
    }

    void readAnnotationFile(){

        QString json_filter = "JSON (*.json)";
        QString file = QFileDialog::getOpenFileName(this,tr("Open File"),"/",json_filter);
        annotationFileLoadedPath = file;
        ui->folder_Path_Annotation->setText(file);

        if(file.isEmpty()){

        }

        else{



            QJsonDocument doc;
            QJsonObject obj;
            QJsonArray array;
            QByteArray data_json;
            QStringList imageNames;

            QString imageName;
            QString shapeClass;
            QString shapeType;
            int image_index;


            QFile input(file);



            if(input.open(QIODevice::ReadOnly | QIODevice::Text)){

                if(ui->canvas->imageList.size() < 1){
                    return;
                }
                else{
                    data_json = input.readAll();
                    doc = doc.fromJson(data_json);
                    obj = doc.object();
                    array = doc.array();



                     QJsonArray imageArray = obj["Images"].toArray();
                     foreach(const QJsonValue & value, imageArray){
                         QJsonArray imageArray = value.toArray();

                         foreach(const QJsonValue & value,imageArray){
                             QJsonObject obj = value.toObject();
                             imageNames.append(obj["Image name"].toString());
                             QString imageName = obj["Image name"].toString();

                             for(int i = 0; i < ui->canvas->imageList.size(); i++){
                                 QString imageNameFromList = ui->canvas->imageList[i].fileName;
                                 if(imageName == imageNameFromList){
                                     image_index = i;
                                 }
                             }
                             QJsonArray shapesArray = obj["Shapes"].toArray();
                             foreach(const QJsonValue & value,shapesArray){
                                 QPolygon polygon;
                                 QJsonObject obj = value.toObject();
                                 //int amountOfPoints = obj["Amout of points"].toInt();
                                 QString shapeClass = obj["Shape Class"].toString();
                                 QString shapeType =  obj["Shape Type"].toString();
                                 QJsonArray pointsArray = obj["Points"].toArray();
                                 foreach(const QJsonValue & value,pointsArray){
                                      QJsonObject obj = value.toObject();
                                      int pointX = obj["X"].toInt();
                                      int pointY = obj["Y"].toInt();
                                      QPoint point = QPoint(pointX,pointY);
                                      polygon.append(point);
                                 }
                                 ui->canvas->imageList[image_index].polygonList.append(Shapes(shapeClass,polygon));
                             }
                         }
                     }
                 }
                annotationFileLoaded = true;
            }

            else{
                 QMessageBox::critical(this,tr("Error"),input.errorString());
            }
        }
    }






    /*!
     * \brief on_btn_Select_Class_File_clicked
     * Trigger for click on button responsible for triggering QFileDialogue, opening a file browse window and selecting a .names file.
     */
    void on_btn_Select_Class_File_clicked();
    /*!
     * \brief on_btn_Select_Image_Folder_clicked
     * Trigger for click on button responsible for triggering QFileDialogue, opening a file browse window and selecting a directory contaiting images.
     */
    void on_btn_Select_Image_Folder_clicked();
    /*!
     * \brief on_image_List_currentTextChanged
     * Check for selected item within image_List, triggers corresponding image to load into the canvas.
     * \param currentText currently selected item within list.
     */
    void on_image_List_currentTextChanged(const QString &currentText);

    void on_dropdown_Sort_Image_activated(int index);

    void on_dropdown_Sort_Class_activated(int index);

    void on_canvas_pressed();

    void on_rad_Btn_Rectangle_toggled(bool checked);

    void on_rad_Btn_Trapezium_toggled(bool checked);

    void on_rad_Btn_Triangle_toggled(bool checked);

    void on_btn_Add_Class_clicked();

    void on_btn_Delete_Class_clicked();

    void on_btn_Save_Annotation_clicked();

    void on_btn_Load_Annotation_clicked();

    void on_Rad_Btn_Edit_toggled(bool checked);

    void on_rad_Btn_Polygon_toggled(bool checked);

    void on_spinBox_Polygon_Sides_valueChanged(int arg1);

    void on_rad_Btn_Move_Corner_toggled(bool checked);

    void on_rad_Btn_Copy_Paste_toggled(bool checked);

    void on_class_List_currentTextChanged(const QString &currentText);

private:
    /*!
     * \brief ui
     * Main user interface for Application.
     */
    Ui::MainWindow *ui;
    /*!
     * \brief image_data
     * QVector responsible for storing data from the QFileInfo about images.
     */
    QVector<QString> image_data;
    /*!
     * \brief images_list
     * Creates a list of images for later use with sorting.
     * NOT IMPLEMENTED.
     */
    List images_list;
    /*!
     * \brief class_data
     * QVector responsible for storing QFile information about easch line from file.
     */
    QVector<QString> class_data;


    /*!
     * \brief classes_list
     * Creates a list of class names used for sorting of classes within the class viewer.
     */
    List classes_list;

    /*!
         * \brief auto save thread
         *object which contains the auto save thread.
         */
    AutoSaveThread autoSave;

};
#endif // MAINWINDOW_H
