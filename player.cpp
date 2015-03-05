#include "player.h"
#include <QtMath>

Player::Player() {
}

void Player::ChooseSex(int sex) {
    if (sex == 1) {
        SetHp(150);
        SetAttack(14);
        SetMiss(8);
        SetBow(93);
    } else {
        SetHp(200);
        SetAttack(13);
        SetMiss(18);
        SetBow(99);
    }
    SetDefend(10);
    SetMoney(0);
    SetExp(0);
    level = 0;
    posx = 6;
    posy = 12;
    floor = 0;
    toward = 3;
    need = 5;
    this->sex = sex;
}

void Player::LevelUp() {
    level += 1;
    SetHp(GetHp() + 10);
    SetAttack(GetAttack() + 1);
    SetDefend(GetDefend() + 1);
    need = qFloor(need*1.5) + 1;
}

Player::~Player() {
}

