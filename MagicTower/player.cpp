#include "player.h"
#include <QtMath>

void Player::ChooseSex(int sex) {
    if (sex == 1) {
        SetHp(150);
        SetAttack(14);
        SetMiss(8);
        SetCrit(93);
    } else {
        SetHp(200);
        SetAttack(13);
        SetMiss(18);
        SetCrit(99);
    }
    SetDefend(10);
    SetMoney(0);
    SetExp(0);
    this->level = 0;
    this->posx = 6;
    this->posy = 12;
    this->floor = 0;
    this->toward = 3;
    this->sex = sex;
    this->need = 5;
}

void Player::LevelUp() {
    level += 1;
    SetHp(GetHp() + 10);
    SetAttack(GetAttack() + 1);
    SetDefend(GetDefend() + 1);
    need = qFloor(need*1.5) + 1;
}

