#pragma once
#include "test7.h"
#include <QtWidgets/QApplication>
#include<iostream>
#include<string>
#include<vector>
#include <chrono>
#include <thread>
#include <windows.h>
#pragma once
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

int testcoin = 0;

class towermiue
{
public:
    towermiue() {}

    towermiue(char choicingg, char shoppingg) {
        choicing = choicingg;
        shopping = shoppingg;
    }

    towermiue(towermiue& tm) {
        choicing = tm.choicing;
        shopping = tm.shopping;
    }

    void showtowermiue() {
        cout << " 炮塔T：价格100$  输入C，暂停选择  选择时输入Y购买，输入其他退出暂停" << endl;
        cout << "   请输入：";
    }
    void choicetower() {
        towerchoicingInput playerchoice;
        choicing = playerchoice.getChar();

        switch (choicing) {
        case 'C':cout << "暂停中" << endl;
            cin >> shopping;
            if (shopping == 'Y' && testcoin >= 100) {
                testcoin -= 100;
                cout << "      已支付，coin:" << testcoin << "$" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1024));
            }
            else if (shopping == 'Y' && testcoin < 100) {
                cout << "    金钱不足";
                std::this_thread::sleep_for(std::chrono::milliseconds(1024));
            }
            else {
                cout << "    继续……";
                std::this_thread::sleep_for(std::chrono::milliseconds(1024));
            }
            break;
        }


    }

    ~towermiue() {}
private:
    char choicing = 0;
    char shopping = 0;

};

