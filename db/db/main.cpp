#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/tmp/database.db");
    bool ok = db.open();

    QSqlQuery query;
    QString sQuery = "Create table people (id int, firstname varchar(64), lastname varchar(64))";
    query.prepare(sQuery);

    if(ok){
        qDebug("OK");
    }
    else {
        qDebug()<< db.lastError().text();
    }


    return a.exec();
}
