#ifndef PLAYER_H
#define PLAYER_H

#include "role.h"
#include <QString>

class Player : public Role {
public:
    Player();
    ~Player();
    int GetLevel() { return level; }
    int GetPosx() { return posx; }
    int GetPosy() { return posy; }
    int GetFloor() {return floor; }
    int GetToward() {return toward; }
    int GetSex() {return sex; }
    int GetNeed() {return need; }

    void SetLevel(int level) { this->level = level; }
    void SetPosx(int posx) { this->posx = posx; }
    void SetPosy(int posy) { this->posy = posy; }
    void SetFloor(int floor) { this->floor = floor; }
    void SetToward(int toward) { this->toward = toward; }
    void SetSex(int sex) { this->sex = sex; }
    void SetNeed(int need) { this->need = need; }
    void ChooseSex(int sex);
    void LevelUp();

private:
    int level;
    int posx;
    int posy;
    int floor;
    int toward;
    int sex;
    int need;
};

#endif //PLAYER_H
