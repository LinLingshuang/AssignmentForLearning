#pragma once
class block
{
public:
    block() {
        x = 0;
        y = 0;
    }
    block(int xx, int yy) {
        x = xx;
        y = yy;
    }
    block(const block& b) {
        x = b.x;
        y = b.y;
    }
    int getx() { return x; }
    int gety() { return y; }

    void createblock(int xm, int ym) {
        x = xm;
        y = ym;

    }


    ~block() {}
private:

    int x;
    int y;

};

