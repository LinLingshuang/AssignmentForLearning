#include <iostream>
using namespace std;
void drawTri(int H) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H - i - 1; j++) {
            std::cout << " ";
        }
        for (int j = 0; j < 1 + 2 * i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}
void drawRect(int H, int W) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void drawParal(int H, int W) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H - i - 1; j++) {
            std::cout << " ";
        }
        for (int j = 0; j < W; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++)
    {
        char choice;
        int h, w;
        std::cin >> choice >> h >> w;
        switch (choice) {
        case'a':
            drawTri(h);
            break;
        case'b':
            drawRect(h, w);
            break;
        case'c':
            drawParal(h, w);
            break;
        default:
            break;
        }

    }
    return 0;
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
