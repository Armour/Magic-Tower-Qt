#include "cheat.h"
#include "player.h"
#include "key.h"
#include "equip.h"
#include <QtMath>

extern Player MyPlr;
extern Equip MyEqp;
extern Key MyKey;
extern int Mode;

void Cheat::slotCheatHp() {             /* Cheat: Hp+100 */
    MyPlr.SetHp(MyPlr.GetHp() + 100);
    emit change();
}

void Cheat::slotCheatAt() {             /* Cheat: Attack+3 */
    MyPlr.SetAttack(MyPlr.GetAttack() + 3);
    emit change();
}

void Cheat::slotCheatDe() {             /* Cheat: Defend+2 */
    MyPlr.SetDefend(MyPlr.GetDefend() + 2);
    emit change();
}

void Cheat::slotCheatMo() {             /* Cheat: Money+50 */
    MyPlr.SetMoney(MyPlr.GetMoney() + 50);
    emit change();
}

void Cheat::slotCheatLe() {             /* Cheat: Level+1 Hp+10 Attack+1 Defend+1 */
    MyPlr.LevelUp();
    emit change();
}

void Cheat::slotCheatRK() {             /* Cheat: RedKey+1 */
    MyKey.SetRed(MyKey.GetRed() + 1);
    emit change();
}

void Cheat::slotCheatBK() {             /* Cheat: BlueKey+1 */
    MyKey.SetBlue(MyKey.GetBlue() + 1);
    emit change();
}

void Cheat::slotCheatYK() {             /* Cheat: YellowKey+1 */
    MyKey.SetYellow(MyKey.GetYellow() + 1);
    emit change();
}

void Cheat::slotCheatBo() {             /* Cheat: Book => have or not */
    MyEqp.SetBook(1 - MyEqp.GetBook());
    emit change();
}

void Cheat::slotCheatSw() {             /* Cheat: Sword => have or not */
    MyEqp.SetSword(1 - MyEqp.GetSword());
    if (MyEqp.GetSword())
        MyPlr.SetAttack(MyPlr.GetAttack() + 10);
    else
        MyPlr.SetAttack(MyPlr.GetAttack() - 10);
    emit change();
}

void Cheat::slotCheatSh() {             /* Cheat: Shield => have or not */
    MyEqp.SetShield(1 - MyEqp.GetShield());
    if (MyEqp.GetShield())
        MyPlr.SetDefend(MyPlr.GetDefend() + 8);
    else
        MyPlr.SetDefend(MyPlr.GetDefend() - 8);
    emit change();
}

void Cheat::slotCheatMode() {             /* Cheat: God mode */
    Mode = -Mode;
    emit change();
}

