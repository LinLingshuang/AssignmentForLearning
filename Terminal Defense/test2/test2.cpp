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
    unsigned long long testtime = 0;
    
    int x = 1;
    int y = 1;

    srand(static_cast<unsigned int>(time(0)));

    while (gamebegin) {
        
        system("cls");

        int random_num0 = rand() % 100;

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
       
        std::cout << "testtime is" << testtime << " "<< endl ;
        std::cout << "---------------------------------------------------" << endl;

        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        int random_num1 = rand() % 2;
        x += random_num1;
        int random_num2 = rand() % 2;
        y += random_num2;
        if (x == 19) {
            x = 1;
        }
        if (y == 39) {
            y = 1;
        }
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 40; j++) {
                if (i == 0||i==19) {
                    std::cout << "#";
                }
                else if(j==0||j==39){
                    std::cout << "#";
                }
                else if (x == i && y == j) {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
                    std::cout << "0";
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
                else{
                    std::cout << " ";
                }
            }
            std::cout << endl;
        }

        std::cout << endl;
        



        testtime += 1;
     
        std::this_thread::sleep_for(std::chrono::milliseconds(128));
        if (testtime == 10e2) {
            gamebegin = false;
        }

    }


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