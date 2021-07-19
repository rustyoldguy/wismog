/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAutor;
    QAction *actionCLS_Textfeld;
    QAction *actionZeige_alle_Zeichen;
    QWidget *centralWidget;
    QPushButton *finito;
    QPushButton *genletter;
    QLineEdit *le_Frequenz;
    QLabel *label;
    QTextEdit *textEdit;
    QPushButton *pbZeichenliste;
    QLineEdit *le_mspeed;
    QLabel *label_2;
    QPushButton *pb_setspeed;
    QComboBox *comboBox;
    QCheckBox *cbx_zahlen;
    QCheckBox *cbx_szeichen;
    QCheckBox *cbx_letter;
    QCheckBox *cbx_umlaute;
    QCheckBox *cbx_francais;
    QCheckBox *cbx_griechische;
    QSlider *SliderVolume;
    QPushButton *Ltest;
    QLabel *label_3;
    QMenuBar *menuBar;
    QMenu *menuInfo;
    QMenu *menuBearbeiten;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(807, 611);
        actionAutor = new QAction(MainWindow);
        actionAutor->setObjectName(QString::fromUtf8("actionAutor"));
        actionCLS_Textfeld = new QAction(MainWindow);
        actionCLS_Textfeld->setObjectName(QString::fromUtf8("actionCLS_Textfeld"));
        actionZeige_alle_Zeichen = new QAction(MainWindow);
        actionZeige_alle_Zeichen->setObjectName(QString::fromUtf8("actionZeige_alle_Zeichen"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        finito = new QPushButton(centralWidget);
        finito->setObjectName(QString::fromUtf8("finito"));
        finito->setGeometry(QRect(600, 430, 88, 34));
        genletter = new QPushButton(centralWidget);
        genletter->setObjectName(QString::fromUtf8("genletter"));
        genletter->setGeometry(QRect(310, 430, 131, 34));
        le_Frequenz = new QLineEdit(centralWidget);
        le_Frequenz->setObjectName(QString::fromUtf8("le_Frequenz"));
        le_Frequenz->setGeometry(QRect(130, 20, 113, 32));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 30, 71, 18));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(50, 80, 571, 321));
        pbZeichenliste = new QPushButton(centralWidget);
        pbZeichenliste->setObjectName(QString::fromUtf8("pbZeichenliste"));
        pbZeichenliste->setGeometry(QRect(470, 430, 111, 34));
        le_mspeed = new QLineEdit(centralWidget);
        le_mspeed->setObjectName(QString::fromUtf8("le_mspeed"));
        le_mspeed->setGeometry(QRect(370, 20, 41, 32));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(300, 30, 51, 18));
        pb_setspeed = new QPushButton(centralWidget);
        pb_setspeed->setObjectName(QString::fromUtf8("pb_setspeed"));
        pb_setspeed->setGeometry(QRect(440, 20, 88, 34));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(560, 20, 83, 32));
        cbx_zahlen = new QCheckBox(centralWidget);
        cbx_zahlen->setObjectName(QString::fromUtf8("cbx_zahlen"));
        cbx_zahlen->setGeometry(QRect(650, 170, 71, 22));
        cbx_szeichen = new QCheckBox(centralWidget);
        cbx_szeichen->setObjectName(QString::fromUtf8("cbx_szeichen"));
        cbx_szeichen->setGeometry(QRect(650, 210, 101, 22));
        cbx_letter = new QCheckBox(centralWidget);
        cbx_letter->setObjectName(QString::fromUtf8("cbx_letter"));
        cbx_letter->setGeometry(QRect(650, 90, 101, 22));
        cbx_umlaute = new QCheckBox(centralWidget);
        cbx_umlaute->setObjectName(QString::fromUtf8("cbx_umlaute"));
        cbx_umlaute->setGeometry(QRect(650, 130, 88, 22));
        cbx_francais = new QCheckBox(centralWidget);
        cbx_francais->setObjectName(QString::fromUtf8("cbx_francais"));
        cbx_francais->setGeometry(QRect(650, 250, 88, 22));
        cbx_griechische = new QCheckBox(centralWidget);
        cbx_griechische->setObjectName(QString::fromUtf8("cbx_griechische"));
        cbx_griechische->setGeometry(QRect(650, 290, 101, 22));
        SliderVolume = new QSlider(centralWidget);
        SliderVolume->setObjectName(QString::fromUtf8("SliderVolume"));
        SliderVolume->setGeometry(QRect(70, 460, 160, 20));
        SliderVolume->setOrientation(Qt::Horizontal);
        Ltest = new QPushButton(centralWidget);
        Ltest->setObjectName(QString::fromUtf8("Ltest"));
        Ltest->setGeometry(QRect(80, 510, 131, 34));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 420, 81, 18));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 807, 30));
        menuInfo = new QMenu(menuBar);
        menuInfo->setObjectName(QString::fromUtf8("menuInfo"));
        menuBearbeiten = new QMenu(menuBar);
        menuBearbeiten->setObjectName(QString::fromUtf8("menuBearbeiten"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuInfo->menuAction());
        menuBar->addAction(menuBearbeiten->menuAction());
        menuInfo->addAction(actionAutor);
        menuBearbeiten->addSeparator();
        menuBearbeiten->addAction(actionCLS_Textfeld);
        menuBearbeiten->addAction(actionZeige_alle_Zeichen);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAutor->setText(QCoreApplication::translate("MainWindow", "&Autor", nullptr));
        actionCLS_Textfeld->setText(QCoreApplication::translate("MainWindow", "&CLS Textfeld", nullptr));
        actionZeige_alle_Zeichen->setText(QCoreApplication::translate("MainWindow", "Zeige_alle_Zeichen", nullptr));
        finito->setText(QCoreApplication::translate("MainWindow", "exit", nullptr));
        genletter->setText(QCoreApplication::translate("MainWindow", "generiere Zeichen", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Frequenz:", nullptr));
        pbZeichenliste->setText(QCoreApplication::translate("MainWindow", "Zeichenliste", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Speed:", nullptr));
        pb_setspeed->setText(QCoreApplication::translate("MainWindow", "Set Speed", nullptr));
        cbx_zahlen->setText(QCoreApplication::translate("MainWindow", "Zahlen", nullptr));
        cbx_szeichen->setText(QCoreApplication::translate("MainWindow", "Satzzeichen", nullptr));
        cbx_letter->setText(QCoreApplication::translate("MainWindow", "Buchstaben", nullptr));
        cbx_umlaute->setText(QCoreApplication::translate("MainWindow", "Umlaute", nullptr));
        cbx_francais->setText(QCoreApplication::translate("MainWindow", "francais", nullptr));
        cbx_griechische->setText(QCoreApplication::translate("MainWindow", "griechische", nullptr));
        Ltest->setText(QCoreApplication::translate("MainWindow", "Sezte Lautstaerke", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Lautstaerke", nullptr));
        menuInfo->setTitle(QCoreApplication::translate("MainWindow", "I&nfo", nullptr));
        menuBearbeiten->setTitle(QCoreApplication::translate("MainWindow", "Bearbei&ten", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
