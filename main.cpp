#include "mainwindow.cpp"
#include "database.cpp"
#include "myview.cpp"
#include "player.cpp"
#include "cheat.cpp"
#include "role.h"
#include "key.h"
#include "equip.h"
#include "monster.h"
#include <QApplication>
#include <QSound>

/* Declare global varible*/
DataBase Mydb;
Player MyPlr;
Monster MyMst[13];
Equip MyEqp;
Key MyKey;
int Map[14][14][10];
int Mode = 1;

/* Main function */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /* Add BGM */
    QSound bgm(a.applicationDirPath() + "/welcome.wav");
    bgm.setLoops(100);
    bgm.play();

    /* Connect database */
    Mydb.Connect(a.applicationDirPath() + "/db.sqlite");

    /* Main window */
    MainWindow w;
    w.show();
    return a.exec();
}
