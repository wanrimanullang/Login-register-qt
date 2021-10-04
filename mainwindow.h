#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql> //##======library database ======
#include <QtDebug> //##======library database ======
#include <QFileInfo> //##======library database ======
#include <vector>

#include "secdialog.h"
#include "daftar.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase mydb;
    void connClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }


    bool connOpen()
    {
        mydb=QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/MAT/Documents/db/mydb.db");

        if(!mydb.open()){
            qDebug()<<("Failed to open the database");
            return false;
    }
        else{
            qDebug()<<("connected....");
            return true;
        }
    }

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Login_clicked();

    void on_pushButton_daftar_clicked();

private:
    Ui::MainWindow *ui;
    SecDialog *secDialog;

};
#endif // MAINWINDOW_H
