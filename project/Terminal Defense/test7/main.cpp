#pragma once
#include "test7.h"
#include <QtWidgets/QApplication>
#include<iostream>
#include<string>
#include<vector>
#include <chrono>
#include <thread>
#include <windows.h>
#include <cstdlib> // 用于rand()和srand()
#include <ctime>   // 用于time()

#include <conio.h>

#include "block.h"
#include "monsterhome.h"
#include "playerhome.h"
#include "color.h"
#include "monster.h"
#include "map.h"
#include "towerchoicingInput.h"
#include "towermiue.h"

using namespace std;



void reloading() {

    system("cls");
    for (int i = 0; i < 13; i++) {

        for (int j = 0; j < 25; j++) {
            if ((j + i < 13) || (j + i > 20)) {
                cout << " ";
            }
            else {
                cout << "*";
            }

        }
        cout << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }


}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    test7 window;
    window.show();
    return app.exec();

    bool miue = true;
    bool gamebegin = false;
    bool helpbegin = false;
    bool gamequit = false;


    unsigned long long testtime = 0;
    int monstersnum = 0;


    towerchoicingInput playerchoice;

    srand(static_cast<unsigned int>(time(0)));

    block as[10];
    for (int i = 0; i < 10; i++) {
        int random_numx = rand() % 18 + 1;
        int random_numy = rand() % 8 + 1;
        as[i].createblock(random_numx, random_numy);

    }
    monster monsters[5];

    monsterhome mh(2, 2);
    playerhome ph(16, 5);
    gamemap::map mymap;

    towermiue mytm;

start:
    while (miue) {

        system("cls");
        setColor(BrightBlue);
        cout << "Terminal Defense Test Version" << endl;
        resetColor();
        cout << "-------------------" << endl;
        setColor(BrightYellow);
        cout << "主菜单" << endl;
        resetColor();
        cout << "-------------------" << endl;
        setColor(BrightCyan);
        cout << "开始：    按S" << endl;

        cout << "玩法说明：按H" << endl;
        setColor(Red);
        cout << "退出：    按Q" << endl;
        resetColor();
        cout << "-------------------" << endl;

        cout << "请输入：";
        char input;

        cin >> input;

        if (input == 'S') {
            gamebegin = true;
            miue = false;
            std::cout << "加载中……" << endl;
        }
        else if (input == 'H') {
            helpbegin = true;
            miue = false;
            std::cout << "加载中……" << endl;
        }
        else if (input == 'Q') {
            gamequit = true;
            miue = false;
            std::cout << "加载中……" << endl;
        }
        else {
            std::cout << "输入错误！" << endl;
            std::cout << "加载中……" << endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1024));
    }

    while (helpbegin) {
        system("cls");

        std::cout << "当前是测试版本，暂无教程说明。" << endl;
        std::cout << "输入B返回标题。" << endl;
        char back;
        std::cin >> back;
        if (back == 'B') {
            miue = true;
            helpbegin = false;
            std::cout << "加载中……" << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1024));
            goto start;
        }
        else {
            std::cout << "输入错误！" << endl;
        }
        std::cout << "加载中……" << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1024));
    }

    while (gamequit) {
        return 0;
    }

    reloading();

    while (gamebegin) {

        system("cls");

        if (testtime % 10 == 0 && monstersnum < 5) {

            monsters[monstersnum].create(mh, ph);
            monstersnum += 1;

        }
        for (int i = 0; i < monstersnum; i++) {
            monsters[i].walk(ph, as);
        }
        setColor(BrightYellow);

        std::cout << "      testtime is " << testtime << endl;
        std::cout << "---------------------------------------------------" << endl;

        resetColor();

        mymap.showmap(monsters, as, mh, ph);



        setColor(BrightYellow);

        std::cout << "---------------------------------------------------" << endl;
        std::cout << "      coin:" << testcoin << "$" << "     monsternumber:" << monstersnum << endl;

        resetColor();

        mytm.showtowermiue();
        mytm.choicetower();

        for (int i = 0; i < monstersnum; i++) {
            monsters[i].monsterinhome(ph);
        }

        testcoin += 5;
        testtime += 1;

        std::this_thread::sleep_for(std::chrono::milliseconds(1024));
        if (testtime == 10e2) {
            gamebegin = false;
        }

    }





    std::cout << "游戏结束。" << endl;

}
