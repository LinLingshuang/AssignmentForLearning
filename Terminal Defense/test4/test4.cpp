#include<iostream>
#include<string>
#include<vector>
#include <chrono>
#include <thread>
#include <windows.h>
#include <cstdlib> // 用于rand()和srand()
#include <ctime>   // 用于time()


using namespace std;

enum ConsoleColor {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Yellow = 6,
    White = 7,
    Gray = 8,
    BrightBlue = 9,
    BrightGreen = 10,
    BrightCyan = 11,
    BrightRed = 12,
    BrightMagenta = 13,
    BrightYellow = 14,
    BrightWhite = 15
};

void setColor(int textColor, int bgColor = Black) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

void resetColor() {
    setColor(White, Black);
}

//---------------------------------
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

class monsterhome {
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

//--------------------------------------------

class playerhome {
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
//-----------------------------------------------

class block {
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
//------------------------------------------------
class monster {
public:
    monster() {
        x = 0;
        y = 0;
        playerhome ph;
        monsterhome mh;
    }
    monster(int xx, int yy, monsterhome mhh,playerhome phh) {
        x = xx;
        y = yy;
        ph = phh;
        mh = mhh;
    }
    monster(const monster& mos) {
        x = mos.x;
        y = mos.y;
        ph = mos.ph;
        mh = mos.mh;
    }
    int getx() { return x; }
    int gety() { return y; }

    void showmonster(int xm, int ym) {


    }
    void blocktouchmonster(int xm, int ym) {


    }
    void walk(playerhome ph) {
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
        else if (x == ph.getx() || y == ph.gety()) {
            int random_numxy = rand() % 2;
            if (random_numxy == 0) {
                y += 1;
            }
            else {
                x += 1;
            }
        }
        if ((x == bs[0].getx() && y == bs[0].gety()) ||
            (x == bs[1].getx() && y == bs[1].gety()) ||
            (x == bs[2].getx() && y == bs[2].gety()) ||
            (x == bs[3].getx() && y == bs[3].gety()) ||
            (x == bs[4].getx() && y == bs[4].gety())) {
            if (x < ph.getx() || y < ph.gety()) {
                x -= 1;
                y += 1;
            }
            else if (x > ph.getx() || y > ph.gety()) {
                x += 1;
                y -= 1;
            }
        }
    }

    void create(monsterhome mh,playerhome ph) {
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


class map {
public:

    map(block am, monster mm[5],block ass[10], playerhome phm, monsterhome mhm) {
        a = am;
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
        a = M.a;
        for (int i = 0; i < 5; i++) {
            m[i] = M.m[i];
        }
        for (int i = 0; i < 10; i++) {
            as[i] = M.as[i];
        }
        ph = M.ph;
        mh = M.mh;
    }
    void showmap(monster m[5],block bs[10], block b1, block b2, block b3, block b4, block b5, monsterhome mh1, playerhome ph1) {

        for (int i = 0; i < weight; i++) {
            cout << "       ";
            for (int j = 0; j < length; j++) {
                if (j == 0 || j == length - 1 || i == 0 || i == weight - 1) {
                    cout << '#';

                }
                else if ((j == m[0].getx() && i == m[0].gety())||
                    (j == m[1].getx() && i == m[1].gety()) || 
                    (j == m[2].getx() && i == m[2].gety()) || 
                    (j == m[3].getx() && i == m[3].gety()) || 
                    (j == m[4].getx() && i == m[4].gety())  ) {
                    setColor(Yellow);

                    cout << 'm';
                    resetColor();
                }
                else if (j == mh1.getx() && i == mh1.gety()) {
                    setColor(Red);

                    cout << 'M';
                    resetColor();
                }
                else if (j == ph1.getx() && i == ph1.gety()) {
                    setColor(BrightBlue);

                    cout << 'H';
                    resetColor();
                }
                else if (j == b1.getx() && i == b1.gety() ||
                    j == b2.getx() && i == b2.gety() ||
                    j == b3.getx() && i == b3.gety() ||
                    j == b4.getx() && i == b4.gety() ||
                    j == b5.getx() && i == b5.gety() ||
                    j == bs[0].getx() && i == bs[0].gety() ||
                    j == bs[1].getx() && i == bs[1].gety() ||
                    j == bs[2].getx() && i == bs[2].gety() ||
                    j == bs[3].getx() && i == bs[3].gety() ||
                    j == bs[4].getx() && i == bs[4].gety()) {
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
    block a;
    block as[10];
    monster m[5];
    playerhome ph;
    monsterhome mh;
};


//-----------------------------



int main() {
    bool miue = true;
    bool gamebegin = false;
    bool helpbegin = false;
    bool gamequit = false;

    int testcoin = 0;
    unsigned long long testtime = 0;
    int monstersnum = 0;


    srand(static_cast<unsigned int>(time(0)));

    block a1(5, 2);
    block a2(13, 5);
    block a3(17, 3);
    block a4(2, 4);
    block a5(7, 3);
    block as[10];
    for (int i = 0; i < 10; i++) {
        int random_numx = rand() % 18 + 1;
        int random_numy = rand() % 8 + 1;
        as[i].createblock(random_numx, random_numy);

    }
    monster monsters[5];

    monsterhome mh(2, 2);
    playerhome ph(16, 5);
    map mymap;



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

            monsters[monstersnum].create(mh,ph);
            monstersnum += 1;

        }
        monsters[monstersnum-1].walk(ph);

        setColor(BrightYellow);

        std::cout << "      testtime is " << testtime << endl;
        std::cout << "---------------------------------------------------" << endl;

        resetColor();

        mymap.showmap(monsters,as, a1, a2, a3, a4, a5, mh, ph);



        setColor(BrightYellow);

        std::cout << "---------------------------------------------------" << endl;
        std::cout << "      coin:" << testcoin << "$" << endl;

        resetColor();

        testcoin += 5;
        testtime += 1;

        std::this_thread::sleep_for(std::chrono::milliseconds(1024));
        if (testtime == 10e2) {
            gamebegin = false;
        }

    }
    std::cout << "游戏结束。" << endl;

}

/*终端颜色输出参考1
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // 你可以组合不同的颜色和背景，具体值可以参考文档
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    std::cout << "This is red text" << std::endl;

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    std::cout << "This is green text" << std::endl;

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 重置为白色
*/
/*终端颜色输出参考2
#include <iostream>
#include <windows.h>

// Windows 控制台颜色代码
enum ConsoleColor {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Yellow = 6,
    White = 7,
    Gray = 8,
    BrightBlue = 9,
    BrightGreen = 10,
    BrightCyan = 11,
    BrightRed = 12,
    BrightMagenta = 13,
    BrightYellow = 14,
    BrightWhite = 15
};

void setColor(int textColor, int bgColor = Black) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

void resetColor() {
    setColor(White, Black);
}

int main() {
    setColor(Red);
    std::cout << "这是红色文字" << std::endl;

    setColor(Green, White);
    std::cout << "这是绿字白底" << std::endl;

    setColor(BrightYellow);
    std::cout << "这是亮黄色文字" << std::endl;

    resetColor();
    return 0;
}*/