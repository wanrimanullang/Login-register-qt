#include "daftar.h"
#include "ui_daftar.h"
#include "mainwindow.h"
#include <QMessageBox>

MainWindow *mainw;

Daftar::Daftar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Daftar)
{
    ui->setupUi(this);
    MainWindow conn;

//========================notifikasi connect database atau tidak=============
    if(!conn.connOpen())
        ui->database2->setText("Failed to open the database");
    else
        ui->database2->setText("connected....");
}

Daftar::~Daftar()
{
    delete ui;
}

void Daftar::on_registrasi_button_clicked()
{
    MainWindow conn;
    QString username,password,pilot;
    username=ui->register_droneid->text();
    password=ui->register_password->text();
    pilot=ui->registrasi_pilot->text();

    if(!conn.connOpen()){
        qDebug()<<"failed to open database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into user (username,password,pilot) values('"+username+"','"+password+"','"+pilot+"')");

    if(qry.exec()){
        QMessageBox::critical(this,tr("save"), tr("saved"));
        conn.connClose();
    }
    else{
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }

}

void Daftar::on_backlogin_clicked()
{
    hide();
    mainw=new MainWindow(this);
    mainw->show();
}

