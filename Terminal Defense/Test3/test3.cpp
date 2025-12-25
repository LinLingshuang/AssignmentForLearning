#include<iostream>
#include<string>
#include<vector>
#include <chrono>
#include <thread>
#include <windows.h>
#include <cstdlib> // 用于rand()和srand()
#include <ctime>   // 用于time()

using namespace std;

const int length = 30;
const int weigth = 20;

int main() {
    bool miue = true;
    bool gamebegin = false;
    bool helpbegin = false;
    bool gamequit = false;

    unsigned long long testtime = 0;

    int x = 1;
    int y = 1;
    bool facetop = true;
    bool facebottom = false;
    bool faceleft = false;
    bool faceright = true;

    srand(static_cast<unsigned int>(time(0)));
    start:
    while (miue) {

        system("cls");

        cout << "Terminal Defense Test Version" << endl;
        cout << "-------------------" << endl;
        cout << "主菜单" << endl;
        cout << "-------------------" << endl;
        cout << "开始：    按S" << endl;
        cout << "玩法说明：按H" << endl;
        cout << "退出：    按Q" << endl;
        cout << "-------------------" << endl;
        cout << "请输入：" ;
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
            goto start ;
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


    while (gamebegin) {

        system("cls");

        int random_num0 = rand() % 100;

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

        std::cout << "testtime is" << testtime << " " << endl;
        std::cout << "---------------------------------------------------" << endl;

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        

        int random_num1 = rand() % 2;
        int random_num2 = rand() % 2;
        if (faceright) {
            x += random_num1;
        }
        else {
            x -= random_num1;
        }
        if (facetop) {
            y += random_num2;
        }
        else {
            y -= random_num2;
        }

        if (x == 18) {
             faceleft = true;
             faceright = false;
        }
        if (y == 8) {
            facetop = false;
            facebottom = true;
        }
        if (x == 1) {
            faceleft = false;
            faceright = true;
        }
        if (y == 1) {
            facetop = true;
            facebottom = false;
        }




        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 20; j++) {
                if (i == 0 || i == 9) {
                    std::cout << "#";
                }
                else if (j == 0 || j == 19) {
                    std::cout << "#";
                }
                else if (y == i && x == j) {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                    std::cout << "0";
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
                else {
                    std::cout << " ";
                }
            }
            std::cout << endl;
        }

        std::cout << endl;




        testtime += 1;

        std::this_thread::sleep_for(std::chrono::milliseconds(32));
        if (testtime == 10e2) {
            gamebegin = false;
        }

    }
    std::cout << "游戏结束。"<<endl;

}

/*终端颜色输出参考
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // 你可以组合不同的颜色和背景，具体值可以参考文档
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    std::cout << "This is red text" << std::endl;

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    std::cout << "This is green text" << std::endl;

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 重置为白色
*/