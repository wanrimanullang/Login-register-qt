#include "secdialog.h"
#include "ui_secdialog.h"
#include "mainwindow.h"

MainWindow *mainww;

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
}

SecDialog::~SecDialog()
{
    delete ui;
}

void SecDialog::on_pushButton_clicked()
{
    hide();
    mainww=new MainWindow(this);
    mainww->show();
}

