#ifndef KEYS_H
#define KEYS_H

class Keys {
public:
    Keys() {}
    ~Keys() {}
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

#endif // KEYS_H
