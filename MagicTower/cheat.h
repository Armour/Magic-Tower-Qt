#ifndef CHEAT_H
#define CHEAT_H
#include <QObject>

class Cheat : public QObject {
    Q_OBJECT
public:
    Cheat() {}
    ~Cheat() {}
signals:
    void change();
public slots:
    void slotCheatHp();
    void slotCheatAttack();
    void slotCheatDefend();
    void slotCheatMoney();
    void slotCheatLevel();
    void slotCheatRedKey();
    void slotCheatBlueKey();
    void slotCheatYellowKey();
    void slotCheatBook();
    void slotCheatSword();
    void slotCheatShield();
    void slotCheatMode();
};

#endif // CHEAT_H
