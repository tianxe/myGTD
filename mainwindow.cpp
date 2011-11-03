#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QtSql/QSqlQuery>
#include<QMessageBox>
#include<QtSql/QSqlTableModel>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlError>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //modelshow();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setHostName("localhost");
    db.setDatabaseName("gtd");
    db.setUserName("root");
    db.setPassword("19062720xp");

    if(!db.open())
    {
        QMessageBox::critical(0,QObject::tr("Connection Error!"),db.lastError().text());

        return false;
    }

    QMessageBox::critical(0,QObject::tr("Connection Suc!"),"Suc! ");
    return true;
}

void MainWindow::modelshow()
{
    //显示
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("student4");
    model->setHeaderData(0,Qt::Horizontal,tr("id"));
    model->select();

    ui->tableView->setModel(model);
    //ui->tableView->adjustSize();
}


void MainWindow::on_pushButton_clicked()
{
    QSqlQuery query;
    //query.exec("create table student4 (id int primary key)");
    int insertvalue=ui->lineEdit->text().toInt();
    QMessageBox::critical(0,QObject::tr("insertvalue"),ui->lineEdit->text());
    //query.exec("insert into student4 values ()");    //到底怎么在“”中使用变量？？？

    query.prepare("insert into student4(id)"
                  "values(:id)");
    query.addBindValue(insertvalue);         //bindvalue不能用于int
    query.exec();

    modelshow();
}

void MainWindow::on_pushButton_2_clicked()
{
    modelshow();
}
