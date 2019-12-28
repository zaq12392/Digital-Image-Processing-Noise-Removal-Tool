/********************************************************************************
** Form generated from reading UI file 'QtGuiApplication2.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUIAPPLICATION2_H
#define UI_QTGUIAPPLICATION2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiApplication2Class
{
public:
    QWidget *centralWidget;
    QPushButton *method1;
    QPushButton *method3;
    QPushButton *method2;
    QPushButton *finish_Bot;
    QPushButton *upload_Bot;
    QGraphicsView *img_src;
    QGraphicsView *img_after;
    QLineEdit *kernel_Input;
    QLabel *label1;
    QPushButton *kernel_Check;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGuiApplication2Class)
    {
        if (QtGuiApplication2Class->objectName().isEmpty())
            QtGuiApplication2Class->setObjectName(QStringLiteral("QtGuiApplication2Class"));
        QtGuiApplication2Class->resize(1127, 665);
        centralWidget = new QWidget(QtGuiApplication2Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        method1 = new QPushButton(centralWidget);
        method1->setObjectName(QStringLiteral("method1"));
        method1->setGeometry(QRect(30, 20, 81, 31));
        method3 = new QPushButton(centralWidget);
        method3->setObjectName(QStringLiteral("method3"));
        method3->setGeometry(QRect(230, 20, 81, 31));
        method2 = new QPushButton(centralWidget);
        method2->setObjectName(QStringLiteral("method2"));
        method2->setGeometry(QRect(130, 20, 81, 31));
        finish_Bot = new QPushButton(centralWidget);
        finish_Bot->setObjectName(QStringLiteral("finish_Bot"));
        finish_Bot->setGeometry(QRect(1020, 570, 81, 31));
        upload_Bot = new QPushButton(centralWidget);
        upload_Bot->setObjectName(QStringLiteral("upload_Bot"));
        upload_Bot->setGeometry(QRect(30, 570, 81, 31));
        img_src = new QGraphicsView(centralWidget);
        img_src->setObjectName(QStringLiteral("img_src"));
        img_src->setGeometry(QRect(30, 60, 531, 501));
        img_after = new QGraphicsView(centralWidget);
        img_after->setObjectName(QStringLiteral("img_after"));
        img_after->setGeometry(QRect(570, 60, 531, 501));
        kernel_Input = new QLineEdit(centralWidget);
        kernel_Input->setObjectName(QStringLiteral("kernel_Input"));
        kernel_Input->setGeometry(QRect(410, 30, 113, 20));
        label1 = new QLabel(centralWidget);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(410, 10, 211, 16));
        kernel_Check = new QPushButton(centralWidget);
        kernel_Check->setObjectName(QStringLiteral("kernel_Check"));
        kernel_Check->setGeometry(QRect(530, 30, 75, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(630, 10, 461, 41));
        QtGuiApplication2Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtGuiApplication2Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1127, 21));
        QtGuiApplication2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGuiApplication2Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtGuiApplication2Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtGuiApplication2Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtGuiApplication2Class->setStatusBar(statusBar);

        retranslateUi(QtGuiApplication2Class);

        QMetaObject::connectSlotsByName(QtGuiApplication2Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiApplication2Class)
    {
        QtGuiApplication2Class->setWindowTitle(QApplication::translate("QtGuiApplication2Class", "QtGuiApplication2", nullptr));
        method1->setText(QApplication::translate("QtGuiApplication2Class", "MedianBlur", nullptr));
        method3->setText(QApplication::translate("QtGuiApplication2Class", "Blur", nullptr));
        method2->setText(QApplication::translate("QtGuiApplication2Class", "GaussianBlur", nullptr));
        finish_Bot->setText(QApplication::translate("QtGuiApplication2Class", "\345\256\214\346\210\220", nullptr));
        upload_Bot->setText(QApplication::translate("QtGuiApplication2Class", "\344\270\212\345\202\263\345\234\226\347\211\207", nullptr));
        label1->setText(QApplication::translate("QtGuiApplication2Class", "kernel \346\225\270\345\200\274\346\233\264\346\224\271   \351\240\220\350\250\255\347\202\2725", nullptr));
        kernel_Check->setText(QApplication::translate("QtGuiApplication2Class", "\347\242\272\345\256\232\346\233\264\346\224\271", nullptr));
        label->setText(QApplication::translate("QtGuiApplication2Class", "\346\263\250\346\204\217\344\272\213\351\240\205: \350\246\201\345\205\210\344\270\212\345\202\263\345\234\226\347\211\207\345\206\215\351\201\270\346\226\271\346\263\225\357\274\214kernel\345\200\274\345\277\205\351\240\210\346\230\257\346\255\243\346\225\264\346\225\270\344\270\224\345\217\252\350\203\275\346\230\257\345\245\207\346\225\270\343\200\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGuiApplication2Class: public Ui_QtGuiApplication2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIAPPLICATION2_H
