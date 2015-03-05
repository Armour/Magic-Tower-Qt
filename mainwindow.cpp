#include "mainwindow.h"
#include "database.h"
#include "player.h"
#include "equip.h"
#include "monster.h"
#include "key.h"
#include "cheat.h"
#include <QTime>
#include <QtMath>
#include <QApplication>

#define GREEN "#00EE00"             // Differnt color
#define BLUE "#0000EE"
#define YELLOW "#EEEE00"
#define PURPLE "#8B008B"
#define RED "#EE0000"

#define PIXLEN 32                   // The pixels of each block
#define X_OFFSET 174                // The offset of x
#define Y_OFFSET 224                // The offset of y
#define DECIMAL 10                  // Decimal system

extern DataBase Mydb;               // Use extern varible
extern Player MyPlr;
extern Key MyKey;
extern Equip MyEqp;
extern Monster MyMst[13];
extern int Map[14][14][10];
extern int Mode;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    /* Initialize private varible */
    cheats = new Cheat();
    scene = new QGraphicsScene;
    view = new MyView(this);

    CreateActions();                            /* Create all actions in mainwindow */
    CreateMenus();                              /* Create all menus in mainwindow */
    scene->setSceneRect(-200,-200,400,400);

    view->setScene(scene);
    view->setMinimumSize(400,400);
    //view->setRenderHint(QPainter::Antialiasing);
    view->show();

    /* Create CONNECT between mainwindow and view */
    connect(view, SIGNAL(quit()), this, SLOT(close()));
    connect(view, SIGNAL(change()), this, SLOT(slotDrawScene()));
    connect(view, SIGNAL(fight(int)), this, SLOT(slotFight(int)));
    connect(view, SIGNAL(events(QString)), this, SLOT(slotEvent(QString)));
    connect(view, SIGNAL(move(int, int)), this, SLOT(slotMovePlayerItem(int, int)));

    /* Set central widget and modify titile */
    setCentralWidget(view);
    resize(550,450);
    setWindowTitle(tr("Magic Tower"));

    /* Welcome page */
    Welcome();
}

MainWindow::~MainWindow() {                  /* Destructor */
    delete scene;
    delete view;
    delete cheats;
}

void MainWindow::Welcome() {
    slotEvent("welcome");                   /* Call the "welcome" slotevent */
}

void MainWindow::CreateActions() {           /* Create all actions in mainwindow */
    /* Initialize all actions */
    clearAct = new QAction(tr("Clear"), this);
    newAct = new QAction(tr("NewGame"), this);
    saveAct = new QAction(tr("Save"), this);
    loadAct = new QAction(tr("Load"), this);
    exitAct = new QAction(tr("Quit"), this);
    chHpAct = new QAction(tr("HP+100"), this);
    chAtAct = new QAction(tr("Attack+3"), this);
    chDeAct = new QAction(tr("Defend+2"), this);
    chMoAct = new QAction(tr("Money+50"), this);
    chLeAct = new QAction(tr("Level+1"), this);
    chYKAct = new QAction(tr("YellowKey+1"), this);
    chBKAct = new QAction(tr("BlueKey+1"), this);
    chRKAct = new QAction(tr("RedKey+1"), this);
    chBoAct = new QAction(tr("Book"), this);
    chSwAct = new QAction(tr("Sword"), this);
    chShAct = new QAction(tr("Shield"), this);
    chModeAct = new QAction(tr("GodMode"), this);

    //newAct->setShortcut(tr("N"));
    //saveAct->setShortcut(tr("S"));
    //loadAct->setShortcut(tr("L"));
    //exitAct->setShortcut(tr("Q"));

    /* Connect all actions */
    connect(cheats, SIGNAL(change()), this, SLOT(slotDrawScene()));
    connect(newAct, SIGNAL(triggered()), this, SLOT(slotNewGame()));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(slotSave()));
    connect(loadAct, SIGNAL(triggered()), this, SLOT(slotLoad()));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
    connect(chHpAct, SIGNAL(triggered()), cheats, SLOT(slotCheatHp()));
    connect(chAtAct, SIGNAL(triggered()), cheats, SLOT(slotCheatAt()));
    connect(chDeAct, SIGNAL(triggered()), cheats, SLOT(slotCheatDe()));
    connect(chMoAct, SIGNAL(triggered()), cheats, SLOT(slotCheatMo()));
    connect(chLeAct, SIGNAL(triggered()), cheats, SLOT(slotCheatLe()));
    connect(chYKAct, SIGNAL(triggered()), cheats, SLOT(slotCheatYK()));
    connect(chBKAct, SIGNAL(triggered()), cheats, SLOT(slotCheatBK()));
    connect(chRKAct, SIGNAL(triggered()), cheats, SLOT(slotCheatRK()));
    connect(chBoAct, SIGNAL(triggered()), cheats, SLOT(slotCheatBo()));
    connect(chSwAct, SIGNAL(triggered()), cheats, SLOT(slotCheatSw()));
    connect(chShAct, SIGNAL(triggered()), cheats, SLOT(slotCheatSh()));
    connect(chModeAct, SIGNAL(triggered()), cheats, SLOT(slotCheatMode()));
}

void MainWindow::CreateMenus() {             /* Create all menus in mainwindow */
    /* file menu */
    QMenu *fileMenu = menuBar()->addMenu(tr(" Menu "));
    fileMenu->addAction(newAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(loadAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    /* cheat menu */
    QMenu *cheatMenu = menuBar()->addMenu(tr(" Cheat! "));
    cheatMenu->addAction(chHpAct);
    cheatMenu->addAction(chAtAct);
    cheatMenu->addAction(chDeAct);
    cheatMenu->addAction(chMoAct);
    cheatMenu->addAction(chLeAct);
    cheatMenu->addSeparator();
    cheatMenu->addAction(chYKAct);
    cheatMenu->addAction(chBKAct);
    cheatMenu->addAction(chRKAct);
    cheatMenu->addSeparator();
    cheatMenu->addAction(chBoAct);
    cheatMenu->addAction(chSwAct);
    cheatMenu->addAction(chShAct);
    cheatMenu->addSeparator();
    cheatMenu->addAction(chModeAct);
}

void MainWindow::CreateInform() {           /* Print player information */
    AddPictureItem(-102, 0, "sidebg");
    AddPictureItem(-97, 30, "side");
    AddPictureItem(-85, 5, "info1");
    AddPictureItem(-65, 60, "sex"+QString::number(MyPlr.GetSex(), DECIMAL));
    AddPictureItem(-82, 130, "info2");
    AddPictureItem(-83, 145, "info3");
    AddPictureItem(-83, 230, "info4");
    AddTextItem(-50, 5, QString::number(MyPlr.GetFloor()+1, DECIMAL), 8, QColor(qrand()%256,qrand()%256,qrand()%256));
    AddTextItem(-65, 100, "Lv "+QString::number(MyPlr.GetLevel() +1, DECIMAL), 10, QColor(qrand()%256,qrand()%256,qrand()%256));
    AddTextItem(-43, 126, QString::number(MyPlr.GetHp(), DECIMAL), 8, QColor(qrand()%256,qrand()%256,qrand()%256));
    AddTextItem(-43, 142, QString::number(MyPlr.GetAttack(), DECIMAL), 8, QColor(qrand()%256,qrand()%256,qrand()%256));
    AddTextItem(-43, 158, QString::number(MyPlr.GetDefend(), DECIMAL), 8, QColor(qrand()%256,qrand()%256,qrand()%256));
    AddTextItem(-43, 174, QString::number(MyPlr.GetMoney(), DECIMAL), 8, QColor(qrand()%256,qrand()%256,qrand()%256));
    AddTextItem(-43, 190, QString::number(MyPlr.GetNeed() - MyPlr.GetExp(), DECIMAL), 8, QColor(qrand()%256,qrand()%256,qrand()%256));
    AddTextItem(-40, 240, QString::number(MyKey.GetYellow(), DECIMAL), 8, QColor(qrand()%256,qrand()%256,qrand()%256));
    AddTextItem(-40, 265, QString::number(MyKey.GetBlue(), DECIMAL), 8, QColor(qrand()%256,qrand()%256,qrand()%256));
    AddTextItem(-40, 290, QString::number(MyKey.GetRed(), DECIMAL), 8, QColor(qrand()%256,qrand()%256,qrand()%256));
    if (Mode == -1)
        AddTextItem(-90, 30, "God Mode!!!", 12, RED);
    if (MyEqp.GetBook())
        AddPictureItem(-63, 323, "book");
    if (MyEqp.GetSword())
        AddPictureItem(-60, 367, "sword");
    if (MyEqp.GetShield())
        AddPictureItem(-60, 405, "shield");
}

void MainWindow::slotDrawScene() {          /* Draw the whole scene */
    if (view->GetStatus() != "main") return;
    Clear();
    CreateInform();
    AddPictureItem(0, 0, "tile");
    for (int i = 0; i < 14; i++)
        for (int j = 0; j < 14; j++)
            AddMapItem(i, j, Map[i][j][MyPlr.GetFloor()]);
    AddPlayerItem(MyPlr.GetPosx(), MyPlr.GetPosy(),
                  MyPlr.GetToward(), MyPlr.GetSex());
}

void MainWindow::slotShop() {               /* Draw the shop scene */
    Clear();
    AddPictureItem(0, 0, "shop");
    CreateInform();
}

void MainWindow::slotBook() {               /* Draw the book scene */
    Clear();
    int exist[30];
    for (int i = 0; i < 30; i++)
        exist[i] = 0;
    for (int i = 0; i < 14; i++)            /* Find monster in this floor */
        for (int j = 0; j < 14; j++)
            if (Map[i][j][MyPlr.GetFloor()] > 10 && Map[i][j][MyPlr.GetFloor()] < 24)
                exist[Map[i][j][MyPlr.GetFloor()]] = 1;
    AddPictureItem(-102, 0, "background");
    int tmp = 0;
    for (int i = 11; i < 24; i++)           /* Draw different monsters imformation */
        if (exist[i]) {
            tmp++;
            AddPictureItem(-80, -26 + tmp*40, QString::number(i, DECIMAL));
            AddTextItem(-35, -28 + tmp*40, "Hp:", 8, GREEN);
            AddTextItem(63, -28 + tmp*40, "Attack:", 8, GREEN);
            AddTextItem(183, -28 + tmp*40, "Defend:", 8, GREEN);
            AddTextItem(196, -12 + tmp*40, "Miss:", 8, PURPLE);
            AddTextItem(343, -12 + tmp*40, "Bow:", 8, PURPLE);
            AddTextItem(-40, -12 + tmp*40, "Exp:", 8, BLUE);
            AddTextItem(62, -12 + tmp*40, "Money:", 8, BLUE);
            AddTextItem(280, -28 + tmp*40, "Expected damage:", 8,  YELLOW);

            AddTextItem(-5, -28 + tmp*40, QString::number(MyMst[i-11].GetHp(), DECIMAL), 8, GREEN);
            AddTextItem(110, -28 + tmp*40, QString::number(MyMst[i-11].GetAttack(), DECIMAL), 8, GREEN);
            AddTextItem(240, -28 + tmp*40, QString::number(MyMst[i-11].GetDefend(), DECIMAL), 8, GREEN);
            AddTextItem(240, -12 + tmp*40, QString::number(MyMst[i-11].GetMiss(), DECIMAL)+"%", 8, PURPLE);
            AddTextItem(380, -12 + tmp*40, QString::number(100 - MyMst[i-11].GetBow(), DECIMAL)+"%", 8, PURPLE);
            AddTextItem(-5, -12 + tmp*40, QString::number(MyMst[i-11].GetExp(), DECIMAL), 8, BLUE);
            AddTextItem(110, -12 + tmp*40, QString::number(MyMst[i-11].GetMoney(), DECIMAL), 8, BLUE);
            AddTextItem(380, -28 + tmp*40, GetExpectedDamage(i-11), 8, YELLOW);
        }
}

void MainWindow::slotEvent(QString str) {           /* Choose different event according to str */
    if (str == "new") slotNewGame();
    else if (str == "boy") MyPlr.ChooseSex(1);
    else if (str == "girl") MyPlr.ChooseSex(0);
    else if (str == "save") slotSave();
    else if (str == "load") slotLoad();
    else if (str == "book") slotBook();
    else if (str == "shop") slotShop();
    else if (str == "quit") close();
    else {
        Clear();
        AddPictureItem(-102, 0, "background");
        if (str == "ending")                /* Different ending according to sex*/
            str += QString::number(MyPlr.GetSex(), DECIMAL);
        AddPictureItem(-102, 0, str);
    }
}

void MainWindow::CreateFight(int num) {     /* Draw the fight background and frames */
    if (MyPlr.GetFloor() == 5)
        AddPictureItem(-102, 0, "firebg");
    else if (MyPlr.GetFloor() == 6)
        AddPictureItem(-102, 0, "icebg");
    else if (MyPlr.GetFloor() == 9)
        AddPictureItem(-102, 0, "highbg");
    else
        AddPictureItem(-102, 0, "lowbg");
    AddPictureItem(40, 50, "fight1");
    AddPictureItem(152, 67, "vs");
    if (MyEqp.GetSword())
        AddPictureItem(53, 70, "sword");
    if (MyEqp.GetShield())
        AddPictureItem(123, 70, "shield");
    AddPictureItem(85, 65, "sex" + QString::number(MyPlr.GetSex(), DECIMAL));
    AddPictureItem(231, 65, QString::number(num, DECIMAL));
    AddPictureItem(40, 140, "fight2");
    AddPictureItem(40, 256, "fight3");
}

void MainWindow::slotFight(int num) {       /* Fight and draw the result */
    Clear();
    CreateFight(num);

    int random, damage, time = 0;
    int plrHp, mstHp;
    int miss1 = 0, miss2 = 0;
    int bow1 = 0, bow2 = 0;
    QString str1, str2;
    QTime t = QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);
    num -= 11;

    mstHp = MyMst[num].GetHp();
    plrHp = MyPlr.GetHp();
    str1 = QString::number(plrHp, DECIMAL) + "   ->   ";
    str2 = QString::number(mstHp, DECIMAL) + "   ->   ";

    /* While not win or lose do, take turns to attack */
    while (1) {
        random = qrand() % 99 + 1;
        damage = qMax(MyPlr.GetAttack() - MyMst[num].GetDefend(), 1);
        damage += qFloor(damage*0.5*(random >= MyPlr.GetBow()));    /* Check if Bow or not */
        mstHp -= damage * (random > MyMst[num].GetMiss());    /* Check if Miss or not */
        if (random <= MyMst[num].GetMiss())
            miss1++;
        if (random >= MyPlr.GetBow())
            bow2++;
        if (mstHp <= 0) {
            mstHp = 0;
            break;
        }
        random = qrand() % 99 + 1;
        damage = qMax(MyMst[num].GetAttack() - MyPlr.GetDefend(), 1);
        damage += qFloor(damage*0.5*(random >= MyMst[num].GetBow()));    /* Check if Bow or not */
        plrHp -= Mode * damage * (random > MyPlr.GetMiss());        /* Check if Miss or not, also check mode */
        if (random <= MyPlr.GetMiss())
            miss2++;
        if (random >= MyMst[num].GetBow())
            bow1++;
        if (plrHp <= 0) {
            plrHp = 0;
            break;
        }
        time++;
    }

    /* Draw the fighting details*/
    str1 += QString::number(plrHp, DECIMAL);
    str2 += QString::number(mstHp, DECIMAL);
    AddTextItem(60, 155, str1, 12, "WHITE");
    AddTextItem(205, 155, str2, 12, "WHITE");
    AddTextItem(75, 171, "Bow : " + QString::number(bow1, DECIMAL), 12, "RED");
    AddTextItem(215, 171, "Bow : " + QString::number(bow2, DECIMAL), 12, "RED");
    AddTextItem(75, 188, "Miss : " + QString::number(miss1, DECIMAL), 12, GREEN);
    AddTextItem(215, 188, "Miss : " + QString::number(miss2, DECIMAL), 12, GREEN);
    AddTextItem(75, 265, "Money + " + QString::number(MyMst[num].GetMoney(), DECIMAL), 12, YELLOW);
    AddTextItem(210, 265, "Exp + " + QString::number(MyMst[num].GetExp(), DECIMAL), 12, YELLOW);

    /* Get the money and experience */
    MyPlr.SetMoney(MyPlr.GetMoney() + MyMst[num].GetMoney());
    MyPlr.SetExp(MyPlr.GetExp() + MyMst[num].GetExp());
    MyPlr.SetHp(plrHp);

    /* Level up (not dead) */
    if (MyPlr.GetExp() >= MyPlr.GetNeed() && MyPlr.GetHp() > 0) {
        MyPlr.SetExp(MyPlr.GetExp() - MyPlr.GetNeed());
        MyPlr.LevelUp();
        AddPictureItem(65, 355, "levelup");
    }
}

void MainWindow::Clear() {              /* Clear all the items in scene */
    QList<QGraphicsItem*> listItem = scene->items();
    while(!listItem.empty()) {
        scene->removeItem(listItem.at(0));
        listItem.removeAt(0);
    }
}

void MainWindow::slotNewGame() {        /* Start a new game */
    Clear();

    /* Load initial data */
    Mydb.LoadMap(0);
    Mydb.LoadEquip(0);
    Mydb.LoadKey(0);
    Mydb.LoadMonster();

    /* Select sex */
    view->SetStatus("select");
    slotEvent("select");
}

void MainWindow::slotSave() {           /* Save data */
    Mydb.SaveMap(1);
    Mydb.SaveEquip(1);
    Mydb.SaveKey(1);
    Mydb.SavePlayer();
}

void MainWindow::slotLoad() {           /* Load data */
    Mydb.LoadMap(1);
    Mydb.LoadEquip(1);
    Mydb.LoadKey(1);
    Mydb.LoadPlayer();
    Mydb.LoadMonster();
    view->SetStatus("main");
    slotDrawScene();
}

void MainWindow::slotMovePlayerItem(int x, int y) {             /* Move player item */
    if (playerItem->zValue() == 0) {
        playerItem->moveBy(x*PIXLEN, y*PIXLEN);
        MyPlr.SetPosx(MyPlr.GetPosx() + x);
        MyPlr.SetPosy(MyPlr.GetPosy() + y);
        Map[MyPlr.GetPosx()][MyPlr.GetPosy()][MyPlr.GetFloor()] = 0;
    }
}

void MainWindow::AddMapItem(int x, int y, int num) {            /* Add a map block item */
    QString str = QApplication::applicationDirPath()+ "/" + QString::number(num, DECIMAL);
    QGraphicsPixmapItem *item = scene->addPixmap(QPixmap(str));
    //item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setPos(x*PIXLEN-X_OFFSET,y*PIXLEN-Y_OFFSET);
}

void MainWindow::AddPictureItem(int x, int y, QString str) {           /* Add a picture item */
    str = QApplication::applicationDirPath()+ "/" + str;
    QGraphicsPixmapItem *item = scene->addPixmap(QPixmap(str));
    //item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setPos(x-X_OFFSET,y-Y_OFFSET);
}

void MainWindow::AddPlayerItem(int x, int y, int toward, int sex) {         /* Add a player item */
    QString str = QApplication::applicationDirPath() + "/1" +
                    QString::number(sex, DECIMAL) +
                    QString::number(toward, DECIMAL);
    playerItem = scene->addPixmap(QPixmap(str));
    playerItem->setPos(x*PIXLEN-X_OFFSET, y*PIXLEN-Y_OFFSET);
}

void MainWindow::AddTextItem(int x, int y, QString str, int size, QColor color) {           /* Add a text string item */
    QFont font("Times", size);
    QGraphicsTextItem *item = new QGraphicsTextItem(str);
    item->setFont(font);
    item->setDefaultTextColor(color);
    scene->addItem(item);
    item->setPos(x-X_OFFSET,y-Y_OFFSET);
}

QString MainWindow::GetExpectedDamage(int num) {            /* Get expected damage of monster[num] */
    int ans;
    int damage1 = MyPlr.GetAttack() - MyMst[num].GetDefend();
    int damage2 = MyMst[num].GetAttack() - MyPlr.GetDefend();
    if (damage1 < 1)
        damage1 = 1;
    if (damage2 < 1)
        damage2 = 1;
    if (MyMst[num].GetHp()%damage1 == 0)
        ans = (MyMst[num].GetHp()/damage1 - 1)*damage2;
    else
        ans = (MyMst[num].GetHp()/damage1)*damage2;
    return QString::number(ans, DECIMAL);
}
