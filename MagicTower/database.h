#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>

class DataBase {
public:
    DataBase();
    ~DataBase();
    void Connect(QString dbpath);
    void SaveMap(int num);
    void LoadMap(int num);
    void SaveTools(int num);
    void LoadTools(int num);
    void SaveKeys(int num);
    void LoadKeys(int num);
    void SavePlayer();
    void LoadPlayer();
    void LoadMonsters();

private:
    QString layer(int num);
    QSqlDatabase db;
};

#endif // DATABASE_H
