#include "view.h"
#include "player.h"
#include "keys.h"
#include "tools.h"
#include <QKeyEvent>

extern Player player;
extern Tools tools;
extern Keys keys;
extern int map[14][14][10];

View::View(QWidget *parent) : QGraphicsView(parent) {         // Initialize the status to "welcome"
    status = "welcome";
    next_step = 0;
}

View::~View() {         // Empty the status string when quit
    status = "";
    next_step = 0;
}

void View::keyPressEvent(QKeyEvent * event) {         // This function will autorun when you press a key
    if (status == "main") {         // Read key and move player
        keyMain(event);
        action();         // Different actions according to Nextstep's num
    } else if (status == "tip" || status == "book" || status == "help") {         // One click then back to main
        SetStatus("main");
        emit change();
    } else if (status == "ending" || status == "fail")         // One click then quit
        emit quit();
    else if (status == "fight")         // One click then if fail then quit else back to main
        keyFight();
    else if (status == "shop")         // Read key and decide which stuff player bought
        keyShop(event);
    else if (status == "welcome")         // Read key and choose to start a new game or load
        keyWelcome(event);
    else if (status == "select")         // Read key and choose sex
        keySelect(event);
}

void View::keyMain(QKeyEvent * event) {
    switch (event->key()) {
        case Qt::Key_Up:        // Move up
            if (access(player.GetPosx(), player.GetPosy()-1))
                emit move(0, -1);
            player.SetToward(1);
            break;
        case Qt::Key_Down:      // Move down
            if (access(player.GetPosx(), player.GetPosy()+1))
                emit move(0, +1);
            player.SetToward(3);
            break;
        case Qt::Key_Left:      // Move left
            if (access(player.GetPosx()-1, player.GetPosy()))
                emit move(-1, 0);
            player.SetToward(2);
            break;
        case Qt::Key_Right:     // Move right
            if (access(player.GetPosx()+1, player.GetPosy()))
                emit move(+1, 0);
            player.SetToward(4);
            break;
        case Qt::Key_B:         // Look up monster book
            if (tools.GetBook()) {
                SetStatus("book");
                emit events("book");
            }
            break;
        case Qt::Key_S:         // Save data
            emit events("save");
            break;
        case Qt::Key_L:         // Load data
            emit events("load");
            break;
        case Qt::Key_Q:         // Quit
            emit events("quit");
            break;
        case Qt::Key_H:         // Get help menu
            SetStatus("help");
            emit events("help");
            break;
        default:
            break;
    }
}

void View::keyShop(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_1:     // Hp + 30 , Money - 50
            if (player.GetMoney() >= 50) {
                player.SetMoney(player.GetMoney() - 50);
                player.SetHp(player.GetHp()+30);
            }
            emit events("shop");
            break;
        case Qt::Key_2:     // Attack + 2, Money - 50
            if (player.GetMoney() >= 50) {
                player.SetMoney(player.GetMoney() - 50);
                player.SetAttack(player.GetAttack()+2);
            }
            emit events("shop");
            break;
        case Qt::Key_3:     // Defend + 1, Money - 50
            if (player.GetMoney() >= 50) {
                player.SetMoney(player.GetMoney() - 50);
                player.SetDefend(player.GetDefend()+1);
            }
            emit events("shop");
            break;
        case Qt::Key_4:     // YellowKey + 1, Money - 40
            if (player.GetMoney() >= 40) {
                player.SetMoney(player.GetMoney() - 40);
                keys.SetYellow(keys.GetYellow()+1);
            }
            emit events("shop");
            break;
        case Qt::Key_5:     // BlueKey + 1, Money - 120
            if (player.GetMoney() >= 120) {
                player.SetMoney(player.GetMoney() - 120);
                keys.SetBlue(keys.GetBlue()+1);
            }
            emit events("shop");
            break;
        case Qt::Key_6:     // RedKey + 1, Money - 300
            if (player.GetMoney() > 300) {
                player.SetMoney(player.GetMoney() - 300);
                keys.SetRed(keys.GetRed()+1);
            }
            emit events("shop");
            break;
        case Qt::Key_Q:     // Back to main
            SetStatus("main");
            emit change();
            break;
        default:
            break;
    }
}

void View::keyWelcome(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_1:     // Start a new game
            emit events("new");
            break;
        case Qt::Key_2:     // Load
            SetStatus("main");
            emit events("load");
            emit change();
            break;
        case Qt::Key_3:     // Quit
            emit events("quit");
            emit change();
            break;
        default:
            break;
    }
}

void View::keySelect(QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_1:     // You are a handsome boy!
            SetStatus("main");
            emit events("boy");
            emit change();
            break;
        case Qt::Key_2:     // You are a beautiful girl~
            SetStatus("main");
            emit events("girl");
            emit change();
            break;
        case Qt::Key_3:     // What!? Who are you!? GET OUT!
            emit events("quit");
            break;
        default:
            break;
    }
}

void View::keyFight() {
    if (player.GetHp() == 0) {
        SetStatus("fail");
        emit events("fail");
    } else {
        SetStatus("main");
        emit change();
    }
}

void View::action() {
    switch (next_step) {
        case 3:
            keys.SetYellow(qMax(keys.GetYellow()-1, 0));
            break;
        case 4:
            keys.SetBlue(qMax(keys.GetBlue()-1, 0));
            break;
        case 5:
            keys.SetRed(qMax(keys.GetRed()-1, 0));
            break;
        case 6:
            keys.SetYellow(keys.GetYellow()+1);
            break;
        case 7:
            keys.SetBlue(keys.GetBlue()+1);
            break;
        case 8:
            keys.SetRed(keys.GetRed()+1);
            break;
        case 10:
            // Oldman's tip
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
            // Fight with normalmonster
            SetStatus("fight");
            emit fight(next_step);
            break;
        case 24:
            // Fight with special monster
            player.SetHp(player.GetHp()/3);
            break;
        case 25:
            // Fight with special monster
            player.SetDefend(player.GetDefend()/3);
            break;
        case 26:
            // Fight with special monster
            player.SetAttack(player.GetAttack()/3);
            break;
        case 27:
            // Sorceress's tip
            SetStatus("tip");
            emit events("tip2");
            break;
        case 28:
            player.SetMoney(player.GetMoney()+15);
            break;
        case 29:
            player.SetHp(player.GetHp()+18);
            break;
        case 30:
            player.SetHp(player.GetHp()+30);
            break;
        case 31:
            tools.SetSword(1);
            player.SetAttack(player.GetAttack()+10);
            break;
        case 32:
            player.SetAttack(player.GetAttack()+3);
            break;
        case 33:
            tools.SetShield(1);
            player.SetDefend(player.GetDefend()+8);
            break;
        case 34:
            player.SetDefend(player.GetDefend()+2);
            break;
        case 35:
            tools.SetBook(1);
            break;
        case 51:
            // Shopping
            SetStatus("shop");
            emit events("shop");
            break;
        case 80:
            // Upstairs
            player.SetFloor(player.GetFloor()+1);
            break;
        case 90:
            // downstairs
            player.SetFloor(player.GetFloor()-1);
            break;
        case 99:
            // End of the game
            SetStatus("ending");
            emit events("ending");
            break;
    }
    if (status == "main")
        emit change();
}

int View::access(int x, int y) {          // Check if map(x,y) is access or not
    int tmp = map[x][y][player.GetFloor()];
    next_step = tmp;
    if (tmp == 0 || (tmp > 5 && tmp < 10) || (tmp > 10 && tmp < 27) || (tmp > 27 && tmp < 35) || tmp == 59 ||
        (tmp == 3 && keys.GetYellow() > 0) || (tmp == 4 && keys.GetBlue() > 0) || (tmp == 5 && keys.GetRed() > 0)) {
        map[x][y][player.GetFloor()] = 0;
        return 1;
    } else
        return 0;
}

