#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>

extern int Map[14][14][10];

class DataBase {
public:
    DataBase();
    ~DataBase();
    void SaveMap(int num);
    void LoadMap(int num);
    void SavePlayer();
    void LoadPlayer();
    void SaveEquip(int num);
    void LoadEquip(int num);
    void SaveKey(int num);
    void LoadKey(int num);
    void LoadMonster();

private:
    QString layer(int num);
    QSqlDatabase db;
};

#endif // MYDATABASE_H
