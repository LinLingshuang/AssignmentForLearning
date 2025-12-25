#pragma once
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
#include "monster.h"

using namespace std;

namespace gamemap {



    class map
    {
    public:

        map(monster mm[5], block ass[10], playerhome phm, monsterhome mhm) {

            for (int i = 0; i < 5; i++) {
                m[i] = mm[i];
            }
            for (int i = 0; i < 10; i++) {
                as[i] = ass[i];
            }
            ph = phm;
            mh = mhm;
        }
        map() {

        }
        map(map& M) {

            for (int i = 0; i < 5; i++) {
                m[i] = M.m[i];
            }
            for (int i = 0; i < 10; i++) {
                as[i] = M.as[i];
            }
            ph = M.ph;
            mh = M.mh;
        }
        void showmap(monster m[5], block bs[10], monsterhome mh1, playerhome ph1) {

            for (int i = 0; i < weight; i++) {
                cout << "       ";
                for (int j = 0; j < length; j++) {
                    if (j == 0 || j == length - 1 || i == 0 || i == weight - 1) {
                        cout << '#';

                    }
                    else if (j == ph1.getx() && i == ph1.gety()) {
                        setColor(BrightBlue);

                        cout << 'H';
                        resetColor();
                    }
                    else if ((j == m[0].getx() && i == m[0].gety()) ||
                        (j == m[1].getx() && i == m[1].gety()) ||
                        (j == m[2].getx() && i == m[2].gety()) ||
                        (j == m[3].getx() && i == m[3].gety()) ||
                        (j == m[4].getx() && i == m[4].gety())) {
                        setColor(Yellow);

                        cout << 'm';
                        resetColor();
                    }
                    else if (j == mh1.getx() && i == mh1.gety()) {
                        setColor(Red);

                        cout << 'M';
                        resetColor();
                    }
                    else if (
                        j == bs[0].getx() && i == bs[0].gety() ||
                        j == bs[1].getx() && i == bs[1].gety() ||
                        j == bs[2].getx() && i == bs[2].gety() ||
                        j == bs[3].getx() && i == bs[3].gety() ||
                        j == bs[4].getx() && i == bs[4].gety() ||
                        j == bs[5].getx() && i == bs[5].gety() ||
                        j == bs[6].getx() && i == bs[6].gety() ||
                        j == bs[7].getx() && i == bs[7].gety() ||
                        j == bs[8].getx() && i == bs[8].gety() ||
                        j == bs[9].getx() && i == bs[9].gety()) {
                        setColor(BrightYellow);

                        cout << '#';

                        resetColor();
                    }
                    else {
                        cout << ' ';
                    }

                }
                cout << endl;


            }



        }


        ~map() {}
    private:
        int length = 20;
        int weight = 10;
        block as[10];
        monster m[5];
        playerhome ph;
        monsterhome mh;

    };

}