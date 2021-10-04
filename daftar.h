#ifndef DAFTAR_H
#define DAFTAR_H

#include <QDialog>
#include <QtSql> //##======library database ======
#include <QtDebug> //##======library database ======
#include <QFileInfo> //##======library database ======
#include <vector>
#include "mainwindow.h"

namespace Ui {
class Daftar;
}

class Daftar : public QDialog
{
    Q_OBJECT

public:

    explicit Daftar(QWidget *parent = 0);
    ~Daftar();

private slots:
    void on_registrasi_button_clicked();

    void on_backlogin_clicked();

private:
    Ui::Daftar *ui;
    QSqlDatabase mydb;
};

#endif // DAFTAR_H
