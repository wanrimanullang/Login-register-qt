#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

Daftar *daftarr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//=================================Gambar QGC========================================
    QPixmap pix("C:/Users/MAT/Documents/Oma-Project/OmaProject--beta/image/qgc.png");
    ui->label_pic->setPixmap(pix);

//================================set label dari database untuk menunjukkan connect atau tidak===========
    if(!connOpen())
        ui->database->setText("Failed to open the database");
    else
        ui->database->setText("connected....");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Login_clicked()
{
    //===============MANUAL USERNAME DAN PASSWORD===================
//    QString username = ui->lineEdit_username->text();
//    QString password = ui->lineEdit_password->text();

//    if (username == "test" && password == "test"){
//        QMessageBox::information(this, "Login", "Username and passowrd is correct");
//        secDialog = new SecDialog(this);
//        secDialog->show();
//    }
//    else {
//        QMessageBox::warning(this, "Login", "Username and password is not correct");
//    }

    QString username,password;
    username=ui->lineEdit_username->text();
    password=ui->lineEdit_password->text();

    if(!connOpen()){
        qDebug()<<"failed to open database";
        return;
    }

    connOpen();
    QSqlQuery qry;
    qry.prepare("select * from user where username='"+username+"' and password = '"+password+"'");

    if(qry.exec()){
        int count=0;
        while(qry.next()){
            count++;
        }
        if(count==1){
            ui->database->setText("username and password is correct"); //membuka halaman home jika password benar
            connClose();
            SecDialog secDialog;
            secDialog.setModal(true);
            secDialog.exec();
        }
        if(count>1){
            ui->database->setText("duplicate username and password");
        }
        if(count<1){
            QMessageBox::warning(this, "Login", "Username and password is not correct");
        }
    }
}

void MainWindow::on_pushButton_daftar_clicked()
{
    hide();
    daftarr=new Daftar(this);
    daftarr->show();
}
