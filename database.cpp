#include "database.h"
#include "player.h"
#include "equip.h"
#include "key.h"
#include "monster.h"

#define MAPLEN 14
#define MAXFLOOR 10
#define DECIMAL 10

extern Player MyPlr;
extern Monster MyMst[13];
extern Equip MyEqp;
extern Key MyKey;

DataBase::DataBase() {          /* Connect to MYSQL/SQLITE database */
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("www.armourcy.com");
    db.setDatabaseName("test");
    db.setUserName("test");
    db.setPassword("cy65x4TdsauQ572w");
    //db.setHostName("localhost");
    //db.setDatabaseName("test");
    //db.setUserName("root");
    //db.setPassword("oioioi");
    db.open();
}

DataBase::~DataBase() {         /* Close database */
    db.close();
}

void DataBase::LoadMap(int num) {           /* Load map data, num = 0 for new, others for old */
    QSqlQuery query(db);
    QString str = "SELECT * FROM map WHERE id = " + QString::number(num+1, DECIMAL);
    query.exec(str);
    query.next();
    for (int i = 0; i < MAXFLOOR; i++) {
        QString floors = query.value(i).toString();
        floors = floors.simplified();
        int tmp = 0;
        while (floors.length() > 3) {
            Map[tmp%MAPLEN][tmp/MAPLEN][i] = floors.left(2).toInt();
            floors.remove(0,3);
            tmp++;
        }
        Map[MAPLEN-1][MAPLEN-1][i] = floors.toInt();
    }
    query.clear();
}

void DataBase::LoadPlayer() {           /* Load player data */
    QSqlQuery query(db);
    query.exec("SELECT * FROM player WHERE id=1");
    query.next();
    MyPlr.SetHp(query.value(0).toInt());
    MyPlr.SetAttack(query.value(1).toInt());
    MyPlr.SetDefend(query.value(2).toInt());
    MyPlr.SetMoney(query.value(3).toInt());
    MyPlr.SetExp(query.value(4).toInt());
    MyPlr.SetMiss(query.value(5).toInt());
    MyPlr.SetBow(query.value(6).toInt());
    MyPlr.SetLevel(query.value(7).toInt());
    MyPlr.SetPosx(query.value(8).toInt());
    MyPlr.SetPosy(query.value(9).toInt());
    MyPlr.SetFloor(query.value(10).toInt());
    MyPlr.SetToward(query.value(11).toInt());
    MyPlr.SetSex(query.value(12).toInt());
    MyPlr.SetNeed(query.value(13).toInt());
    query.clear();
}

void DataBase::LoadMonster() {          /* Load monster data */
    QSqlQuery query(db);
    query.exec("SELECT * FROM monster");
    for (int i = 0; i < 13; i++) {
        query.next();
        MyMst[i].SetHp(query.value(0).toInt());
        MyMst[i].SetAttack(query.value(1).toInt());
        MyMst[i].SetDefend(query.value(2).toInt());
        MyMst[i].SetMoney(query.value(3).toInt());
        MyMst[i].SetExp(query.value(4).toInt());
        MyMst[i].SetMiss(query.value(5).toInt());
        MyMst[i].SetBow(query.value(6).toInt());
    }
    query.clear();
}

void DataBase::LoadEquip(int num) {         /* Load equipment data, num = 0 for new, others for old */
    QSqlQuery query(db);
    QString str = "SELECT * FROM equip WHERE id = " + QString::number(num+1, DECIMAL);
    query.exec(str);
    query.next();
    MyEqp.SetBook(query.value(0).toInt());
    MyEqp.SetShield(query.value(1).toInt());
    MyEqp.SetSword(query.value(2).toInt());
    query.clear();
}

void DataBase::LoadKey(int num) {           /* Load key data, num = 0 for new, others for old*/
    QSqlQuery query(db);
    QString str = "SELECT * FROM mkey WHERE id = " + QString::number(num+1, DECIMAL);
    query.exec(str);
    query.next();
    MyKey.SetRed(query.value(0).toInt());
    MyKey.SetBlue(query.value(1).toInt());
    MyKey.SetYellow(query.value(2).toInt());
    query.clear();
}

void DataBase::SaveMap(int num) {           /* Save map data */
    QSqlQuery query(db);
    QString str = "UPDATE map SET layer0=?, layer1=?, layer2=?, layer3=?, layer4=?, layer5=?, layer6=?, layer7=?, layer8=?, layer9=? WHERE id=" + QString::number(num+1, DECIMAL);
    query.prepare(str);
    query.bindValue(0, layer(0));
    query.bindValue(1, layer(1));
    query.bindValue(2, layer(2));
    query.bindValue(3, layer(3));
    query.bindValue(4, layer(4));
    query.bindValue(5, layer(5));
    query.bindValue(6, layer(6));
    query.bindValue(7, layer(7));
    query.bindValue(8, layer(8));
    query.bindValue(9, layer(9));
    query.exec();
    query.clear();
}

void DataBase::SavePlayer() {           /* Save player data */
    QSqlQuery query(db);
    QString str = "UPDATE player SET hp=?, attack=?, defend=?,money=?, exp=?, miss=?, bow=?, level=?, posx=?, posy=?, floor=?, toward=?, sex=?, need=? WHERE id=1";
    query.prepare(str);
    query.bindValue(0, MyPlr.GetHp());
    query.bindValue(1, MyPlr.GetAttack());
    query.bindValue(2, MyPlr.GetDefend());
    query.bindValue(3, MyPlr.GetMoney());
    query.bindValue(4, MyPlr.GetExp());
    query.bindValue(5, MyPlr.GetMiss());
    query.bindValue(6, MyPlr.GetBow());
    query.bindValue(7, MyPlr.GetLevel());
    query.bindValue(8, MyPlr.GetPosx());
    query.bindValue(9, MyPlr.GetPosy());
    query.bindValue(10, MyPlr.GetFloor());
    query.bindValue(11, MyPlr.GetToward());
    query.bindValue(12, MyPlr.GetSex());
    query.bindValue(13, MyPlr.GetNeed());
    query.exec();
    query.clear();
}

void DataBase::SaveEquip(int num) {         /* Save equipment data */
    QSqlQuery query(db);
    QString str = "UPDATE equip SET book=?, shield=?, sword=? WHERE id=" + QString::number(num+1, DECIMAL);
    query.prepare(str);
    query.bindValue(0, MyEqp.GetBook());
    query.bindValue(1, MyEqp.GetShield());
    query.bindValue(2, MyEqp.GetSword());
    query.exec();
    query.clear();
}

void DataBase::SaveKey(int num) {           /* Save key data */
    QSqlQuery query(db);
    QString str = "UPDATE mkey SET red=?, blue=?, yellow=? WHERE id=" + QString::number(num+1, DECIMAL);
    query.prepare(str);
    query.bindValue(0, MyKey.GetRed());
    query.bindValue(1, MyKey.GetBlue());
    query.bindValue(2, MyKey.GetYellow());
    query.exec();
    query.clear();
}

QString DataBase::layer(int num) {          /* Construct layer string  */
    QString str = " ";
    for (int i = 0; i < 14; i++)
        for (int j = 0; j < 14; j++) {
            if (Map[j][i][num] < 10)
                str += "0";
            str += QString::number(Map[j][i][num], DECIMAL);
            str += " ";
        }
    return str;
}

