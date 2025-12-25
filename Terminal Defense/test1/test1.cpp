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
	bool gamebegin = true;
    unsigned long long testtime=0;
    int clear = 0;

    srand(static_cast<unsigned int>(time(0)));

	while (gamebegin) {
        if (clear == 100) {
            system("cls");
            clear = 0;
         }

        int random_num = rand() % 100;

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);


        std::cout << "testtime is" << testtime << " ";
        for (int i = 0; i < 100; i++) {
            if (i != random_num) {
                std::cout << '#';
            }
            else {
                std::cout << '%';
            }
        }
        std::cout << endl;

        testtime += 1;
        clear+=1;
        std::this_thread::sleep_for(std::chrono::milliseconds(128));
        if (testtime == 10e10) {
            gamebegin = false;
        }

	}


}
/*刷新参考
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    while (true) {
        // 清屏（可选）
        system("clear");  // Linux/Mac
        // system("cls");  // Windows
        
        // 输出游戏界面
        std::cout << "=== 游戏界面 ===" << std::endl;
        std::cout << "玩家位置: (10, 20)" << std::endl;
        std::cout << "分数: 100" << std::endl;
        
        // 控制刷新速度 - 每秒60帧
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
        
        // 或者每秒30帧
        // std::this_thread::sleep_for(std::chrono::milliseconds(33));
    }
    return 0;
}*/

/*终端颜色输出参考
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // 你可以组合不同的颜色和背景，具体值可以参考文档
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    std::cout << "This is red text" << std::endl;

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    std::cout << "This is green text" << std::endl;

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 重置为白色
*/