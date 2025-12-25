#pragma once
#include<iostream>
#include<string>
#include<vector>
#include <chrono>
#include <thread>
#include <windows.h>
#include <cstdlib> // 用于rand()和srand()
#include <ctime>   // 用于time()

#include "block.h"
#include "monsterhome.h"
#include "playerhome.h"
#include "color.h"
using namespace std;

class monster
{
public:
    monster() {
        x = 0;
        y = 0;
        playerhome ph;
        monsterhome mh;
    }
    monster(int xx, int yy, monsterhome mhh, playerhome phh, block bss[10]) {
        x = xx;
        y = yy;
        for (int i = 0; i < 10; i++) {
            bs[i] = bss[i];
        }
        ph = phh;
        mh = mhh;
    }
    monster(const monster& mos) {
        x = mos.x;
        y = mos.y;
        for (int i = 0; i < 10; i++) {
            bs[i] = mos.bs[i];
        }
        ph = mos.ph;
        mh = mos.mh;
    }
    int getx() { return x; }
    int gety() { return y; }

    void monsterinhome(playerhome ph) {
        if (x == ph.getx() && y == ph.gety()) {
            setColor(Red);
            cout << "      你被击败了！" << endl;
            resetColor();

        }

    }
    void blocktouchmonster(int xm, int ym) {


    }
    void walk(playerhome ph, block bs[10]) {
        if (x < ph.getx() && y < ph.gety()) {
            int random_numxy = rand() % 2;
            if (random_numxy == 0) {
                y += 1;
            }
            else {
                x += 1;
            }
        }
        else if (x > ph.getx() && y > ph.gety()) {
            int random_numxy = rand() % 2;
            if (random_numxy == 0) {
                y -= 1;
            }
            else {
                x -= 1;
            }
        }
        else if (x < ph.getx() && y > ph.gety()) {
            int random_numxy = rand() % 2;
            if (random_numxy == 0) {
                y -= 1;
            }
            else {
                x += 1;
            }
        }
        else if (x > ph.getx() && y < ph.gety()) {
            int random_numxy = rand() % 2;
            if (random_numxy == 0) {
                y += 1;
            }
            else {
                x -= 1;
            }
        }
        else if (x == ph.getx() && y < ph.gety()) {
            y += 1;
        }
        else if (x == ph.getx() && y > ph.gety()) {
            y -= 1;
        }
        else if (x < ph.getx() && y == ph.gety()) {
            x += 1;
        }
        else if (x > ph.getx() && y == ph.gety()) {
            x -= 1;
        }
        if (
            (x == bs[0].getx() && y == bs[0].gety()) ||
            (x == bs[1].getx() && y == bs[1].gety()) ||
            (x == bs[2].getx() && y == bs[2].gety()) ||
            (x == bs[3].getx() && y == bs[3].gety()) ||
            (x == bs[4].getx() && y == bs[4].gety()) ||
            (x == bs[5].getx() && y == bs[5].gety()) ||
            (x == bs[6].getx() && y == bs[6].gety()) ||
            (x == bs[7].getx() && y == bs[7].gety()) ||
            (x == bs[8].getx() && y == bs[8].gety()) ||
            (x == bs[9].getx() && y == bs[9].gety())) {
            if (x < ph.getx() || y < ph.gety()) {
                x -= 1;
                y -= 1;
            }
            else if (x > ph.getx() || y > ph.gety()) {
                x += 1;
                y += 1;
            }
        }
    }

    void create(monsterhome mh, playerhome ph) {
        x = mh.getx();
        y = mh.gety();
        ph = ph;
    }

    void changexy() {
        int random_numx = rand() % 18 + 1;
        int random_numy = rand() % 8 + 1;

        x = random_numx;
        y = random_numy;
    }

    ~monster() {}
private:

    int x;
    int y;
    block bs[10];
    playerhome ph;
    monsterhome mh;
};

