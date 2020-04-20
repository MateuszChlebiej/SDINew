/********************************************************************************
** Form generated from reading UI file 'addclasswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCLASSWINDOW_H
#define UI_ADDCLASSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AddClassWindow
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *newClassEntry;
    QLabel *lbl_enter_class_name;

    void setupUi(QDialog *AddClassWindow)
    {
        if (AddClassWindow->objectName().isEmpty())
            AddClassWindow->setObjectName(QString::fromUtf8("AddClassWindow"));
        AddClassWindow->resize(339, 97);
        buttonBox = new QDialogButtonBox(AddClassWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(-60, 50, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        newClassEntry = new QLineEdit(AddClassWindow);
        newClassEntry->setObjectName(QString::fromUtf8("newClassEntry"));
        newClassEntry->setGeometry(QRect(170, 20, 113, 20));
        lbl_enter_class_name = new QLabel(AddClassWindow);
        lbl_enter_class_name->setObjectName(QString::fromUtf8("lbl_enter_class_name"));
        lbl_enter_class_name->setGeometry(QRect(20, 20, 141, 21));

        retranslateUi(AddClassWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddClassWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddClassWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddClassWindow);
    } // setupUi

    void retranslateUi(QDialog *AddClassWindow)
    {
        AddClassWindow->setWindowTitle(QCoreApplication::translate("AddClassWindow", "Dialog", nullptr));
        lbl_enter_class_name->setText(QCoreApplication::translate("AddClassWindow", "Enter new class name here:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddClassWindow: public Ui_AddClassWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCLASSWINDOW_H
