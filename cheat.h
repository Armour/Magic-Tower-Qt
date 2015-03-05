#ifndef CHEAT_H
#define CHEAT_H
#include <QObject>

class Cheat : public QObject {
    Q_OBJECT
public:
    Cheat() {}
    //~Cheat();
signals:
    void change();
public slots:
    void slotCheatHp();
    void slotCheatAt();
    void slotCheatDe();
    void slotCheatMo();
    void slotCheatLe();
    void slotCheatRK();
    void slotCheatBK();
    void slotCheatYK();
    void slotCheatBo();
    void slotCheatSw();
    void slotCheatSh();
    void slotCheatMode();
};

#endif // CHEAT_H
