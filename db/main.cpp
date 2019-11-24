#include <QCoreApplication>
#include <QtSql>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/tmp/database.db");
    bool ok = db.open();

    if(ok){
        qDebug("OK");
    }
    else {
        qDebug()<< db.lastError().text();
    }
    QSqlQuery query;
    QString sQuery = "Create table people (id int, firstname varchar(64), lastname varchar(64))";
    query.prepare(sQuery);
    if(!query.exec()){
        qDebug()<< db.lastError().text();
    }

    QSqlQuery query1 ;
    QString sQuery1 = "Insert into people (id,firstname,lastname) values (1, :first, :last)";
    query1.prepare(sQuery1);
    query1.bindValue(":first","Jan");
    query1.bindValue(":last","kowalski");


    if(!query1.exec()){
        qDebug()<< db.lastError().text();
    }

    QSqlQuery query2;
    if(query2.exec("select * from people")){
        while(query2.next()){
            qDebug()<<query2.value("firstname").toString();
            qDebug()<<query2.value("lastname").toString();
        }
    }
    else {
        qDebug()<<db.lastError().text();
    }




    return a.exec();
}
