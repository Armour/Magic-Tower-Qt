#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "view.h"
#include "cheat.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QMenuBar>
#include <QString>
#include <QSound>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void Welcome();
    void Clear();
    void CreateActions();
    void CreateMenus();
    void CreateInform();
    void CreateFight(int num);

    void AddMapItem(int x, int y, int num);
    void AddPictureItem(int x, int y, QString str);
    void AddPlayerItem(int x, int y, int toward, int sex);
    void AddTextItem(int x, int y, QString str, int size, QColor color);
    QString GetExpectedDamage(int num);

public slots:
    void slotDrawScene();
    void slotNewGame();
    void slotSaveGame();
    void slotLoadGame();
    void slotMovePlayerItem(int x, int y);
    void slotShop();
    void slotBook();
    void slotFight(int num);
    void slotEvent(QString str);

private:
    View *view;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *playerItem;
    QAction *clear;
    QAction *newGame;
    QAction *loadGame;
    QAction *saveGame;
    QAction *exitGame;
    QAction *cheatHp;
    QAction *cheatAttack;
    QAction *cheatDefend;
    QAction *cheatMoney;
    QAction *cheatLevel;
    QAction *cheatYellowKey;
    QAction *cheatBlueKey;
    QAction *cheatRedKey;
    QAction *cheatBook;
    QAction *cheatSword;
    QAction *cheatShield;
    QAction *cheatMode;
    Cheat *cheats;
};

#endif // MAINWINDOW_H
