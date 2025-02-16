#include <QCoreApplication>

#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtNetwork/QNetworkAccessManager>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSqlDatabase sqldb;
    sqldb.setDatabaseName("ABCD");
    QNetworkAccessManager net;
    net.connectToHost("host", 12);

    return a.exec();
}
