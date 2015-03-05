#ifndef EQUIP_H
#define EQUIP_H

class Equip {
public:
    //Equip();
    //~Equip();
    int GetBook() { return book; }
    int GetShield() { return shield; }
    int GetSword() { return sword; }
    void SetBook(int book)	{ this->book = book; }
    void SetShield(int shield) { this->shield = shield; }
    void SetSword(int sword) { this->sword = sword; }

private:
    int book;
    int shield;
    int sword;
};

#endif // EQUIP_H
