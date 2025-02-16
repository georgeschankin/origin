#include "mainwindow.h"

#include <QApplication>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtNetwork/QNetworkAccessManager>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QSqlDatabase sqldb;
    sqldb.setDatabaseName("ABCD");
    QNetworkAccessManager net;
    net.connectToHost("host", 12);
    w.show();
    return a.exec();
}
