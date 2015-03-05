#ifndef KEY_H
#define KEY_H

class Key {
public:
    //Key();
    //~Key();
    int GetRed() { return red; }
    int GetBlue() { return blue; }
    int GetYellow() { return yellow; }
    void SetRed(int red)	{ this->red = red; }
    void SetBlue(int blue) { this->blue = blue; }
    void SetYellow(int yellow) { this->yellow = yellow; }

private:
    int red;
    int blue;
    int yellow;
};

#endif // KEY_H
