#pragma once
class monsterhome
{
public:
    monsterhome() {
        x = 0;
        y = 0;
    }
    monsterhome(int xx, int yy) {
        x = xx;
        y = yy;
    }
    monsterhome(monsterhome& moshome) {
        x = moshome.x;
        y = moshome.y;
    }
    int getx() { return x; }
    int gety() { return y; }


    ~monsterhome() {}
private:

    int x;
    int y;

};

