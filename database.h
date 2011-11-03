#ifndef DATABASE_H
#define DATABASE_H

#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlError>
#include<QMessageBox>
#include<QtSql/QSqlTableModel>


bool databaseConnection()
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

void modelshow()
{
    //ÏÔÊ¾
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable(student4);
    model->setHeaderData(0,Qt::Horizontal,tr("id"));
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->adjustSize();
}


#endif // DATABASE_H
