#ifndef TOOLS_H
#define TOOLS_H

class Tools {
public:
    Tools() {}
    ~Tools() {}
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

#endif // TOOLS_H
