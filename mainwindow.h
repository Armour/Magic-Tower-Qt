#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "myview.h"
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
    void slotSave();
    void slotLoad();
    void slotMovePlayerItem(int x, int y);
    void slotShop();
    void slotBook();
    void slotFight(int num);
    void slotEvent(QString str);

private:
    MyView *view;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *playerItem;
    QAction *clearAct;
    QAction *saveAct;
    QAction *newAct;
    QAction *loadAct;
    QAction *exitAct;
    QAction *chHpAct;
    QAction *chAtAct;
    QAction *chDeAct;
    QAction *chMoAct;
    QAction *chLeAct;
    QAction *chYKAct;
    QAction *chBKAct;
    QAction *chRKAct;
    QAction *chBoAct;
    QAction *chSwAct;
    QAction *chShAct;
    QAction *chModeAct;
    Cheat *cheats;
};

#endif // MAINWINDOW_H
