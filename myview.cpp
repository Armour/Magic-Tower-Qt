#include "myview.h"
#include "player.h"
#include "key.h"
#include "equip.h"
#include <QKeyEvent>

extern Player MyPlr;
extern Equip MyEqp;
extern Key MyKey;
extern int Map[14][14][10];

MyView::MyView(QWidget *parent) :
    QGraphicsView(parent) {         /* Initialize the status to "welcome" */
    status = "welcome";
    NextStep = 0;
}

MyView::~MyView() {          /* Empty the status string */
    status = "";
    NextStep = 0;
}

void MyView::keyPressEvent(QKeyEvent * event) {         /* This function will autorun when you press a key */
    if (status == "main") { /* Read key and move player */
        keyMain(event);
        action();       /* Different actions according to Nextstep's num */
    } else if (status == "tip" || status == "book" || status == "help") {   /* One click then back to main */
        SetStatus("main");
        emit change();
    } else if (status == "ending" || status == "fail")    /* One click then quit */
        emit quit();
    else if (status == "fight")     /* One click then if fail then quit else back to main */
        keyFight();
    else if (status == "shop")      /* Read key and decide which stuff player bought */
        keyShop(event);
    else if (status == "welcome")      /* Read key and choose to start a new game or load */
        keyWelcome(event);
    else if (status == "select")      /* Read key and choose sex */
        keySelect(event);
}

void MyView::keyMain(QKeyEvent * event) {
    switch (event->key()) {
        case Qt::Key_Up:        /* Move up */
            if (access(MyPlr.GetPosx(), MyPlr.GetPosy()-1))
                emit move(0, -1);
            MyPlr.SetToward(1);
            break;
        case Qt::Key_Down:      /* Move down */
            if (access(MyPlr.GetPosx(), MyPlr.GetPosy()+1))
                emit move(0, +1);
            MyPlr.SetToward(3);
            break;
        case Qt::Key_Left:      /* Move left */
            if (access(MyPlr.GetPosx()-1, MyPlr.GetPosy()))
                emit move(-1, 0);
            MyPlr.SetToward(2);
            break;
        case Qt::Key_Right:     /* Move right */
            if (access(MyPlr.GetPosx()+1, MyPlr.GetPosy()))
                emit move(+1, 0);
            MyPlr.SetToward(4);
            break;
        case Qt::Key_B:         /* Look up monster book */
            if (MyEqp.GetBook()) {
                SetStatus("book");
                emit events("book");
            }
            break;
        case Qt::Key_S:         /* Save data */
            emit events("save");
            break;
        case Qt::Key_L:         /* Load data */
            emit events("load");
            break;
        case Qt::Key_Q:         /* Quit */
            emit events("quit");
            break;
        case Qt::Key_H:         /* Get help menu */
            SetStatus("help");
            emit events("help");
            break;
        default:
            break;
    }
}

void MyView::keyShop(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_1:     /* Hp + 30 , Money - 50 */
            if (MyPlr.GetMoney() >= 50) {
                MyPlr.SetMoney(MyPlr.GetMoney() - 50);
                MyPlr.SetHp(MyPlr.GetHp()+30);
            }
            emit events("shop");
            break;
        case Qt::Key_2:     /* Attack + 2, Money - 50 */
            if (MyPlr.GetMoney() >= 50) {
                MyPlr.SetMoney(MyPlr.GetMoney() - 50);
                MyPlr.SetAttack(MyPlr.GetAttack()+2);
            }
            emit events("shop");
            break;
        case Qt::Key_3:     /* Defend + 1, Money - 50 */
            if (MyPlr.GetMoney() >= 50) {
                MyPlr.SetMoney(MyPlr.GetMoney() - 50);
                MyPlr.SetDefend(MyPlr.GetDefend()+1);
            }
            emit events("shop");
            break;
        case Qt::Key_4:     /* YellowKey + 1, Money - 40 */
            if (MyPlr.GetMoney() >= 40) {
                MyPlr.SetMoney(MyPlr.GetMoney() - 40);
                MyKey.SetYellow(MyKey.GetYellow()+1);
            }
            emit events("shop");
            break;
        case Qt::Key_5:     /* BlueKey + 1, Money - 120 */
            if (MyPlr.GetMoney() >= 120) {
                MyPlr.SetMoney(MyPlr.GetMoney() - 120);
                MyKey.SetBlue(MyKey.GetBlue()+1);
            }
            emit events("shop");
            break;
        case Qt::Key_6:     /* RedKey + 1, Money - 300 */
            if (MyPlr.GetMoney() > 300) {
                MyPlr.SetMoney(MyPlr.GetMoney() - 300);
                MyKey.SetRed(MyKey.GetRed()+1);
            }
            emit events("shop");
            break;
        case Qt::Key_Q:     /* Back to main */
            SetStatus("main");
            emit change();
            break;
        default:
            break;
    }
}

void MyView::keyWelcome(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_1:     /* Start a new game */
            emit events("new");
            break;
        case Qt::Key_2:     /* Load */
            SetStatus("main");
            emit events("load");
            emit change();
            break;
        case Qt::Key_3:     /* Quit */
            emit events("quit");
            emit change();
            break;
        default:
            break;
    }
}

void MyView::keySelect(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_1:     /* You are a handsome boy! */
            SetStatus("main");
            emit events("boy");
            emit change();
            break;
        case Qt::Key_2:     /* You are a beautiful girl~ */
            SetStatus("main");
            emit events("girl");
            emit change();
            break;
        case Qt::Key_3:     /* What!? Who are you!? GET OUT! */
            emit events("quit");
            break;
        default:
            break;
    }
}

void MyView::keyFight() {
    if (MyPlr.GetHp() == 0) {
        SetStatus("fail");
        emit events("fail");
    } else {
        SetStatus("main");
        emit change();
    }
}

void MyView::action() {
    switch (NextStep) {
        case 3:
            MyKey.SetYellow(qMax(MyKey.GetYellow()-1, 0));
            break;
        case 4:
            MyKey.SetBlue(qMax(MyKey.GetBlue()-1, 0));
            break;
        case 5:
            MyKey.SetRed(qMax(MyKey.GetRed()-1, 0));
            break;
        case 6:
            MyKey.SetYellow(MyKey.GetYellow()+1);
            break;
        case 7:
            MyKey.SetBlue(MyKey.GetBlue()+1);
            break;
        case 8:
            MyKey.SetRed(MyKey.GetRed()+1);
            break;
        case 10:
            /* Oldman's tip */
            SetStatus("tip");
            emit events("tip1");
            break;
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
            /* Fight with monster */
            SetStatus("fight");
            emit fight(NextStep);
            break;
        case 24:
            MyPlr.SetHp(MyPlr.GetHp()/3);
            break;
        case 25:
            MyPlr.SetDefend(MyPlr.GetDefend()/3);
            break;
        case 26:
            MyPlr.SetAttack(MyPlr.GetAttack()/3);
            break;
        case 27:
            /* Sorceress's tip */
            SetStatus("tip");
            emit events("tip2");
            break;
        case 28:
            MyPlr.SetMoney(MyPlr.GetMoney()+15);
            break;
        case 29:
            MyPlr.SetHp(MyPlr.GetHp()+18);
            break;
        case 30:
            MyPlr.SetHp(MyPlr.GetHp()+30);
            break;
        case 31:
            MyEqp.SetSword(1);
            MyPlr.SetAttack(MyPlr.GetAttack()+10);
            break;
        case 32:
            MyPlr.SetAttack(MyPlr.GetAttack()+3);
            break;
        case 33:
            MyEqp.SetShield(1);
            MyPlr.SetDefend(MyPlr.GetDefend()+8);
            break;
        case 34:
            MyPlr.SetDefend(MyPlr.GetDefend()+2);
            break;
        case 35:
            MyEqp.SetBook(1);
            break;
        case 51:
            /* Shopping */
            SetStatus("shop");
            emit events("shop");
            break;
        case 80:
            /* Upstairs */
            MyPlr.SetFloor(MyPlr.GetFloor()+1);
            break;
        case 90:
            /* downstairs */
            MyPlr.SetFloor(MyPlr.GetFloor()-1);
            break;
        case 99:
            /* End of the game */;
            SetStatus("ending");
            emit events("ending");
            break;
    }
    if (status == "main")
        emit change();
}

int MyView::access(int x, int y) {          /* Check if map(x,y) is access or not */
    int tmp = Map[x][y][MyPlr.GetFloor()];
    NextStep = tmp;
    if (tmp == 0 || (tmp > 5 && tmp < 10) || (tmp > 10 && tmp < 27) ||
        (tmp > 27 && tmp < 35) || tmp == 59 || (tmp == 3 && MyKey.GetYellow() > 0) ||
        (tmp == 4 && MyKey.GetBlue() > 0) || (tmp == 5 && MyKey.GetRed() > 0)) {
        Map[x][y][MyPlr.GetFloor()] = 0;
        return 1;
    } else
        return 0;
}

