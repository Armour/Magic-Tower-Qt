#ifndef Role_H
#define Role_H

class Role {
public:
    Role() {}
    ~Role() {}
    int GetHp() { return hp; }
    int GetAttack() { return attack; }
    int GetDefend() { return defend; }
    int GetMoney() { return money; }
    int GetExp() { return exp; }
    int GetMiss() { return miss; }
    int GetCrit() { return crit; }

    void SetHp(int hp)	{ this->hp = hp; }
    void SetAttack(int attack) { this->attack = attack; }
    void SetDefend(int defend) { this->defend = defend; }
    void SetMoney(int money) { this->money = money; }
    void SetExp(int exp) { this->exp = exp; }
    void SetMiss(int miss) { this->miss = miss; }
    void SetCrit(int crit) { this->crit = crit; }

private:
    int hp;
    int attack;
    int defend;
    int money;
    int exp;
    int miss;
    int crit;
};

#endif // Role_H
