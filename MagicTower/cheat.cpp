#include "cheat.h"
#include "player.h"
#include "keys.h"
#include "tools.h"
#include <QtMath>

extern Player player;
extern Tools tools;
extern Keys keys;
extern int mode;

void Cheat::slotCheatHp() {             // Cheat: Hp+100
    player.SetHp(player.GetHp() + 100);
    emit change();
}

void Cheat::slotCheatAttack() {         // Cheat: Attack+3
    player.SetAttack(player.GetAttack() + 3);
    emit change();
}

void Cheat::slotCheatDefend() {         // Cheat: Defend+2
    player.SetDefend(player.GetDefend() + 2);
    emit change();
}

void Cheat::slotCheatMoney() {          // Cheat: Money+50
    player.SetMoney(player.GetMoney() + 50);
    emit change();
}

void Cheat::slotCheatLevel() {          // Cheat: Level+1, Hp+10, Attack+1, Defend+1
    player.LevelUp();
    emit change();
}

void Cheat::slotCheatRedKey() {         // Cheat: RedKey+1
    keys.SetRed(keys.GetRed() + 1);
    emit change();
}

void Cheat::slotCheatBlueKey() {        // Cheat: BlueKey+1
    keys.SetBlue(keys.GetBlue() + 1);
    emit change();
}

void Cheat::slotCheatYellowKey() {      // Cheat: YellowKey+1
    keys.SetYellow(keys.GetYellow() + 1);
    emit change();
}

void Cheat::slotCheatBook() {           // Cheat: Book
    tools.SetBook(1 - tools.GetBook());
    emit change();
}

void Cheat::slotCheatSword() {          // Cheat: Sword
    tools.SetSword(1 - tools.GetSword());
    if (tools.GetSword())
        player.SetAttack(player.GetAttack() + 10);
    else
        player.SetAttack(player.GetAttack() - 10);
    emit change();
}

void Cheat::slotCheatShield() {         // Cheat: Shield
    tools.SetShield(1 - tools.GetShield());
    if (tools.GetShield())
        player.SetDefend(player.GetDefend() + 8);
    else
        player.SetDefend(player.GetDefend() - 8);
    emit change();
}

void Cheat::slotCheatMode() {           // Cheat: God mode
    mode = -mode;
    emit change();
}

