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
#include "annotationclass.h"
#include "image.h"
#include"canvas.h"
#include "addclasswindow.h"
#include "class.h"
#include "list.h"
#include"autoSaveThread.h"
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

    QString classFilePath;

    Canvas canvas;
    static int shapeIndex;

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
        for(int i = 0; i< size; i++){
            for(int j=0; j<size-1; j++){

                if(ascending_or_descending == ">"){
                    if(item_list[j]>item_list[j+1]){
                        QString tmp;
                        tmp = item_list[j];
                        item_list[j] = item_list[j+1];
                        item_list[j+1] = tmp;
                    }
                }
                if(ascending_or_descending == "<"){
                    if(item_list[j]<item_list[j+1]){
                        QString tmp;
                        tmp = item_list[j];
                        item_list[j] = item_list[j+1];
                        item_list[j+1] = tmp;
                    }
                }
            }
        }
        return item_list;
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
        }

        QTextStream in(&file);
        while(!in.atEnd()){

            //Each line = different class/
            QString class_name = in.readLine();

            //New instance of AnnotationClass class,  NEEDS TO BE MADE SO IT IS STORED IN AN ARRAY, THEN MOST OF ABOVE STORAGE IS NOT NEEDED!!!!
            AnnotationClass object_name;

            //Set current objects name and line number.
            object_name.set_name_and_line(class_name,line_number);

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


                images_list.InsertNodeImage(lineNum,var.baseName(),var.filePath(),lastMod);
                lineNum++;
            }

       }
        images_list.GetNameList();
        //Change gui label showing path of current directory.
        ui->folder_Path_Image->setText(folder_name);
    }

    void saveAnnotationFile(){

        //get size of imageslist
        //go through images list, each image at a time, for each image
            //get image name
            //go through imagepolygonList
                //get shape type
                //get amount of coordinates
                //get coordinates

        /*int list_size = canvas.imageList.size();
        QJsonObject recordObject;
        recordObject.insert("Number of annotated images", QJsonValue::fromVariant(list_size));
        for(int i = 0; i<list_size; i++){
            QString image_name = canvas.imageList[i].fileName;
            int shape_list_size = canvas.imageList[i].polygonList.size();
            QJsonObject imageObject;
            imageObject.insert("Image Name", image_name);
            imageObject.insert("Number of shapes", shape_list_size);
            for(int j = 0; j<shape_list_size; j++){
                QString shape_type = canvas.imageList[i].polygonList[j].shapeName;
                int shape_points_size = canvas,imageList[i].polygonList[j].pointsList.size(); ////////To be filled out as i dont know where coordniated are stored.
                QJsonArray shapeVectorsArray;
                shapeVectorsArray.push_back(shape_type);
                shapeVectorsArray.push_back(amount of shape points);  //needs to be filled out
                for(int k = 0; k<shape_points_size; k++){
                    shapeVectorsArray.push_back("Shape Coordinate!!!!!");

                }
               imageObject.insert("Shape", shapeVectorsArray);
            }
        }




        QString json_filter = "JSON (*.json)";
        QString file = QFileDialog::getSaveFileName(this,tr("Save File"),"/",json_filter);

        if(file.isEmpty()){

        }
        else{

            QJsonDocument doc(recordObject);
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
        }*/
    }

    void readAnnotationFile(){
       /* QString json_filter = "JSON (*.json)";
        QString file = QFileDialog::getOpenFileName(this,tr("Open File"),"/",json_filter);

        if(file.isEmpty()){
        }
        else{

            //Go through file, for each image
                //Store image in annotated image list
                //Go through each image shape
                    //add to shapesList
                    //add each point to shape points list


            QJsonDocument doc;
            QJsonObject obj;
            QByteArray data_json;
            QFile input(file);
            if(input.open(QIODevice::ReadOnly | QIODevice::Text)){
                data_json = input.readAll();
                doc = doc.fromJson(data_json);
                obj = doc.object();

                QString value1 = obj["Value1"].toString();
                qDebug()<<value1;
                QString value2 = obj["Value2"].toString();
                 qDebug()<<value2;
                QString value3 = obj["Value3"].toString();
                 qDebug()<<value3;
                QString value4 = obj["Value4"].toString();
                 qDebug()<<value4;

                 int number_of_images = obj["Number of annotated images"].toInt();
                 for(int i = 0; i<number_of_images; i++){
                     //add to annotated image list
                      int number_of_shapes = obj["Number shapes"].toInt();
                     for(int j = 0; j< number_of_shapes; j++){
                         //add shape To Image shape list
                         //set shape type
                         //get number of points
                         for(int k = 0; k< numberOfShapePoints; k++){
                             //add point to list
                         }
                     }
                 }

                QMessageBox::information(this,tr("Message"),tr("Document Open"));
            }
            else{
                 QMessageBox::critical(this,tr("Error"),input.errorString());
            }
        }*/
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


    AutoSaveThread autoSave;

};
#endif // MAINWINDOW_H
