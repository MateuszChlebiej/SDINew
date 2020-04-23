/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <canvas.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout;
    Canvas *canvas;
    QVBoxLayout *vertical_Selection_Panel;
    QVBoxLayout *vertical_Image_Pane;
    QFrame *line_4;
    QHBoxLayout *horizontal_Top_Image_Pane;
    QLabel *lbl_Panel_Name_Image;
    QLabel *folder_Path_Image;
    QListWidget *image_List;
    QComboBox *dropdown_Sort_Image;
    QPushButton *btn_Select_Image_Folder;
    QFrame *line_2;
    QVBoxLayout *vertical_Classes_Pane;
    QHBoxLayout *horizontal_Top_Classes_Pane;
    QLabel *lbl_Panel_Name_Class;
    QLabel *folder_Path_Class;
    QListWidget *class_List;
    QHBoxLayout *horizontal_Bottom_Classes_Pane;
    QComboBox *dropdown_Sort_Class;
    QPushButton *btn_Add_Class;
    QPushButton *btn_Delete_Class;
    QPushButton *btn_Select_Class_File;
    QFrame *line_3;
    QHBoxLayout *horizontal_Annotation_Pane;
    QVBoxLayout *vertical_Left_Annotation_Pane;
    QPushButton *btn_Save_Annotation;
    QPushButton *btn_Load_Annotation;
    QVBoxLayout *vertical_Right_Annotation_Pane;
    QLabel *lbl_Current_Annotation_FIle;
    QLabel *folder_Path_Annotation;
    QFrame *line_1;
    QGridLayout *grid_Shapes_Pane;
    QRadioButton *rad_Btn_Trapezium;
    QSpinBox *spinBox_Polygon_Sides;
    QRadioButton *rad_Btn_Triangle;
    QRadioButton *rad_Btn_Rectangle;
    QLabel *lbl_Panel_Shapes_Name;
    QRadioButton *rad_Btn_Polygon;
    QLabel *lbl_Polygon_Side;
    QRadioButton *Rad_Btn_Edit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1198, 803);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        canvas = new Canvas(centralwidget);
        canvas->setObjectName(QString::fromUtf8("canvas"));

        formLayout->setWidget(0, QFormLayout::FieldRole, canvas);

        vertical_Selection_Panel = new QVBoxLayout();
        vertical_Selection_Panel->setObjectName(QString::fromUtf8("vertical_Selection_Panel"));
        vertical_Selection_Panel->setSizeConstraint(QLayout::SetDefaultConstraint);
        vertical_Image_Pane = new QVBoxLayout();
        vertical_Image_Pane->setObjectName(QString::fromUtf8("vertical_Image_Pane"));
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        vertical_Image_Pane->addWidget(line_4);

        horizontal_Top_Image_Pane = new QHBoxLayout();
        horizontal_Top_Image_Pane->setSpacing(60);
        horizontal_Top_Image_Pane->setObjectName(QString::fromUtf8("horizontal_Top_Image_Pane"));
        lbl_Panel_Name_Image = new QLabel(centralwidget);
        lbl_Panel_Name_Image->setObjectName(QString::fromUtf8("lbl_Panel_Name_Image"));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Serif"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        lbl_Panel_Name_Image->setFont(font);

        horizontal_Top_Image_Pane->addWidget(lbl_Panel_Name_Image);


        vertical_Image_Pane->addLayout(horizontal_Top_Image_Pane);

        folder_Path_Image = new QLabel(centralwidget);
        folder_Path_Image->setObjectName(QString::fromUtf8("folder_Path_Image"));
        folder_Path_Image->setMaximumSize(QSize(273, 16777215));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        folder_Path_Image->setFont(font1);

        vertical_Image_Pane->addWidget(folder_Path_Image);

        image_List = new QListWidget(centralwidget);
        image_List->setObjectName(QString::fromUtf8("image_List"));

        vertical_Image_Pane->addWidget(image_List);

        dropdown_Sort_Image = new QComboBox(centralwidget);
        dropdown_Sort_Image->addItem(QString());
        dropdown_Sort_Image->addItem(QString());
        dropdown_Sort_Image->addItem(QString());
        dropdown_Sort_Image->addItem(QString());
        dropdown_Sort_Image->setObjectName(QString::fromUtf8("dropdown_Sort_Image"));
        dropdown_Sort_Image->setEnabled(true);
        dropdown_Sort_Image->setEditable(false);
        dropdown_Sort_Image->setIconSize(QSize(16, 16));

        vertical_Image_Pane->addWidget(dropdown_Sort_Image);

        btn_Select_Image_Folder = new QPushButton(centralwidget);
        btn_Select_Image_Folder->setObjectName(QString::fromUtf8("btn_Select_Image_Folder"));

        vertical_Image_Pane->addWidget(btn_Select_Image_Folder);


        vertical_Selection_Panel->addLayout(vertical_Image_Pane);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setLineWidth(2);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        vertical_Selection_Panel->addWidget(line_2);

        vertical_Classes_Pane = new QVBoxLayout();
        vertical_Classes_Pane->setObjectName(QString::fromUtf8("vertical_Classes_Pane"));
        horizontal_Top_Classes_Pane = new QHBoxLayout();
        horizontal_Top_Classes_Pane->setSpacing(60);
        horizontal_Top_Classes_Pane->setObjectName(QString::fromUtf8("horizontal_Top_Classes_Pane"));
        lbl_Panel_Name_Class = new QLabel(centralwidget);
        lbl_Panel_Name_Class->setObjectName(QString::fromUtf8("lbl_Panel_Name_Class"));
        lbl_Panel_Name_Class->setFont(font);

        horizontal_Top_Classes_Pane->addWidget(lbl_Panel_Name_Class);


        vertical_Classes_Pane->addLayout(horizontal_Top_Classes_Pane);

        folder_Path_Class = new QLabel(centralwidget);
        folder_Path_Class->setObjectName(QString::fromUtf8("folder_Path_Class"));
        folder_Path_Class->setMaximumSize(QSize(273, 16777215));
        folder_Path_Class->setFont(font1);

        vertical_Classes_Pane->addWidget(folder_Path_Class);

        class_List = new QListWidget(centralwidget);
        class_List->setObjectName(QString::fromUtf8("class_List"));

        vertical_Classes_Pane->addWidget(class_List);

        horizontal_Bottom_Classes_Pane = new QHBoxLayout();
        horizontal_Bottom_Classes_Pane->setObjectName(QString::fromUtf8("horizontal_Bottom_Classes_Pane"));
        dropdown_Sort_Class = new QComboBox(centralwidget);
        dropdown_Sort_Class->addItem(QString());
        dropdown_Sort_Class->addItem(QString());
        dropdown_Sort_Class->setObjectName(QString::fromUtf8("dropdown_Sort_Class"));
        dropdown_Sort_Class->setEnabled(true);
        dropdown_Sort_Class->setEditable(false);
        dropdown_Sort_Class->setIconSize(QSize(16, 16));

        horizontal_Bottom_Classes_Pane->addWidget(dropdown_Sort_Class);

        btn_Add_Class = new QPushButton(centralwidget);
        btn_Add_Class->setObjectName(QString::fromUtf8("btn_Add_Class"));

        horizontal_Bottom_Classes_Pane->addWidget(btn_Add_Class);

        btn_Delete_Class = new QPushButton(centralwidget);
        btn_Delete_Class->setObjectName(QString::fromUtf8("btn_Delete_Class"));

        horizontal_Bottom_Classes_Pane->addWidget(btn_Delete_Class);


        vertical_Classes_Pane->addLayout(horizontal_Bottom_Classes_Pane);

        btn_Select_Class_File = new QPushButton(centralwidget);
        btn_Select_Class_File->setObjectName(QString::fromUtf8("btn_Select_Class_File"));

        vertical_Classes_Pane->addWidget(btn_Select_Class_File);


        vertical_Selection_Panel->addLayout(vertical_Classes_Pane);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        vertical_Selection_Panel->addWidget(line_3);

        horizontal_Annotation_Pane = new QHBoxLayout();
        horizontal_Annotation_Pane->setObjectName(QString::fromUtf8("horizontal_Annotation_Pane"));
        vertical_Left_Annotation_Pane = new QVBoxLayout();
        vertical_Left_Annotation_Pane->setObjectName(QString::fromUtf8("vertical_Left_Annotation_Pane"));
        btn_Save_Annotation = new QPushButton(centralwidget);
        btn_Save_Annotation->setObjectName(QString::fromUtf8("btn_Save_Annotation"));

        vertical_Left_Annotation_Pane->addWidget(btn_Save_Annotation);

        btn_Load_Annotation = new QPushButton(centralwidget);
        btn_Load_Annotation->setObjectName(QString::fromUtf8("btn_Load_Annotation"));

        vertical_Left_Annotation_Pane->addWidget(btn_Load_Annotation);


        horizontal_Annotation_Pane->addLayout(vertical_Left_Annotation_Pane);

        vertical_Right_Annotation_Pane = new QVBoxLayout();
        vertical_Right_Annotation_Pane->setObjectName(QString::fromUtf8("vertical_Right_Annotation_Pane"));
        lbl_Current_Annotation_FIle = new QLabel(centralwidget);
        lbl_Current_Annotation_FIle->setObjectName(QString::fromUtf8("lbl_Current_Annotation_FIle"));

        vertical_Right_Annotation_Pane->addWidget(lbl_Current_Annotation_FIle);

        folder_Path_Annotation = new QLabel(centralwidget);
        folder_Path_Annotation->setObjectName(QString::fromUtf8("folder_Path_Annotation"));

        vertical_Right_Annotation_Pane->addWidget(folder_Path_Annotation);


        horizontal_Annotation_Pane->addLayout(vertical_Right_Annotation_Pane);


        vertical_Selection_Panel->addLayout(horizontal_Annotation_Pane);

        line_1 = new QFrame(centralwidget);
        line_1->setObjectName(QString::fromUtf8("line_1"));
        line_1->setFrameShadow(QFrame::Sunken);
        line_1->setLineWidth(2);
        line_1->setFrameShape(QFrame::HLine);

        vertical_Selection_Panel->addWidget(line_1);

        grid_Shapes_Pane = new QGridLayout();
        grid_Shapes_Pane->setObjectName(QString::fromUtf8("grid_Shapes_Pane"));
        rad_Btn_Trapezium = new QRadioButton(centralwidget);
        rad_Btn_Trapezium->setObjectName(QString::fromUtf8("rad_Btn_Trapezium"));
        QFont font2;
        font2.setPointSize(10);
        rad_Btn_Trapezium->setFont(font2);

        grid_Shapes_Pane->addWidget(rad_Btn_Trapezium, 4, 0, 1, 1);

        spinBox_Polygon_Sides = new QSpinBox(centralwidget);
        spinBox_Polygon_Sides->setObjectName(QString::fromUtf8("spinBox_Polygon_Sides"));

        grid_Shapes_Pane->addWidget(spinBox_Polygon_Sides, 1, 2, 1, 1);

        rad_Btn_Triangle = new QRadioButton(centralwidget);
        rad_Btn_Triangle->setObjectName(QString::fromUtf8("rad_Btn_Triangle"));
        rad_Btn_Triangle->setFont(font2);

        grid_Shapes_Pane->addWidget(rad_Btn_Triangle, 4, 1, 1, 2);

        rad_Btn_Rectangle = new QRadioButton(centralwidget);
        rad_Btn_Rectangle->setObjectName(QString::fromUtf8("rad_Btn_Rectangle"));
        rad_Btn_Rectangle->setFont(font2);

        grid_Shapes_Pane->addWidget(rad_Btn_Rectangle, 1, 0, 1, 1);

        lbl_Panel_Shapes_Name = new QLabel(centralwidget);
        lbl_Panel_Shapes_Name->setObjectName(QString::fromUtf8("lbl_Panel_Shapes_Name"));
        lbl_Panel_Shapes_Name->setFont(font);

        grid_Shapes_Pane->addWidget(lbl_Panel_Shapes_Name, 0, 0, 1, 1);

        rad_Btn_Polygon = new QRadioButton(centralwidget);
        rad_Btn_Polygon->setObjectName(QString::fromUtf8("rad_Btn_Polygon"));
        rad_Btn_Polygon->setFont(font2);

        grid_Shapes_Pane->addWidget(rad_Btn_Polygon, 1, 1, 1, 1);

        lbl_Polygon_Side = new QLabel(centralwidget);
        lbl_Polygon_Side->setObjectName(QString::fromUtf8("lbl_Polygon_Side"));

        grid_Shapes_Pane->addWidget(lbl_Polygon_Side, 1, 3, 1, 1);

        Rad_Btn_Edit = new QRadioButton(centralwidget);
        Rad_Btn_Edit->setObjectName(QString::fromUtf8("Rad_Btn_Edit"));
        Rad_Btn_Edit->setFont(font2);

        grid_Shapes_Pane->addWidget(Rad_Btn_Edit, 5, 0, 1, 1);


        vertical_Selection_Panel->addLayout(grid_Shapes_Pane);


        formLayout->setLayout(0, QFormLayout::LabelRole, vertical_Selection_Panel);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1198, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        dropdown_Sort_Image->setCurrentIndex(0);
        dropdown_Sort_Class->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        canvas->setText(QString());
        lbl_Panel_Name_Image->setText(QCoreApplication::translate("MainWindow", "Images", nullptr));
        folder_Path_Image->setText(QCoreApplication::translate("MainWindow", "Path", nullptr));
        dropdown_Sort_Image->setItemText(0, QCoreApplication::translate("MainWindow", "Ascending Name", nullptr));
        dropdown_Sort_Image->setItemText(1, QCoreApplication::translate("MainWindow", "Descenting Name", nullptr));
        dropdown_Sort_Image->setItemText(2, QCoreApplication::translate("MainWindow", "Ascending Date", nullptr));
        dropdown_Sort_Image->setItemText(3, QCoreApplication::translate("MainWindow", "Descending Date", nullptr));

#if QT_CONFIG(tooltip)
        dropdown_Sort_Image->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        dropdown_Sort_Image->setCurrentText(QCoreApplication::translate("MainWindow", "Ascending Name", nullptr));
        btn_Select_Image_Folder->setText(QCoreApplication::translate("MainWindow", "Select target folder", nullptr));
        lbl_Panel_Name_Class->setText(QCoreApplication::translate("MainWindow", "Classes", nullptr));
        folder_Path_Class->setText(QCoreApplication::translate("MainWindow", "Path", nullptr));
        dropdown_Sort_Class->setItemText(0, QCoreApplication::translate("MainWindow", "Ascending Name", nullptr));
        dropdown_Sort_Class->setItemText(1, QCoreApplication::translate("MainWindow", "Descenting Name", nullptr));

#if QT_CONFIG(tooltip)
        dropdown_Sort_Class->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        dropdown_Sort_Class->setCurrentText(QCoreApplication::translate("MainWindow", "Ascending Name", nullptr));
        btn_Add_Class->setText(QCoreApplication::translate("MainWindow", "Add Class", nullptr));
        btn_Delete_Class->setText(QCoreApplication::translate("MainWindow", "Delete Class", nullptr));
        btn_Select_Class_File->setText(QCoreApplication::translate("MainWindow", "Select target file", nullptr));
        btn_Save_Annotation->setText(QCoreApplication::translate("MainWindow", "Save Annotations", nullptr));
        btn_Load_Annotation->setText(QCoreApplication::translate("MainWindow", "Load Annotations", nullptr));
        lbl_Current_Annotation_FIle->setText(QCoreApplication::translate("MainWindow", "Current annotation file:", nullptr));
        folder_Path_Annotation->setText(QCoreApplication::translate("MainWindow", "......", nullptr));
        rad_Btn_Trapezium->setText(QCoreApplication::translate("MainWindow", "Trapezium", nullptr));
        rad_Btn_Triangle->setText(QCoreApplication::translate("MainWindow", "Triangle", nullptr));
        rad_Btn_Rectangle->setText(QCoreApplication::translate("MainWindow", "Rectangle", nullptr));
        lbl_Panel_Shapes_Name->setText(QCoreApplication::translate("MainWindow", "Shapes", nullptr));
        rad_Btn_Polygon->setText(QCoreApplication::translate("MainWindow", "Polygon", nullptr));
        lbl_Polygon_Side->setText(QCoreApplication::translate("MainWindow", "Sides", nullptr));
        Rad_Btn_Edit->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
