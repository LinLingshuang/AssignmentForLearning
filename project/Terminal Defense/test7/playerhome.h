#pragma once
class playerhome
{
public:
    playerhome() {
        x = 0;
        y = 0;
    }
    playerhome(int xx, int yy) {
        x = xx;
        y = yy;
    }
    playerhome(playerhome& home) {
        x = home.x;
        y = home.y;
    }
    int getx() { return x; }
    int gety() { return y; }


    ~playerhome() {}
private:

    int x;
    int y;

};

