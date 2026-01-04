/*3. 基于类的重载，实现给定初始值的前缀、后缀自增与自减操作
【问题描述】请编写一个抽象类Point，可以通过操作符重载的形式，实现任意输入值的前缀、后缀自增和自减操作，并进行显示。
该题重点在于操作符重载，和前后缀自增自减实现，样例中的显示逻辑不是考核重点（已提供Point.cpp中实现输出的部分代码），
main中是否实现类似循环、判断不作为考核重点，因此提供main.cpp工程文件作为示范，和Point.h声明文件作为约束和提示，请独自完成Point.cpp函数实现文件的编写。
【样例说明】请对照示例代码（可在“提交源文件”标题下的中文“注意”提示语句最后，找到Point.h和main.cpp文件的下载位置）加以理解。
强调，务必认真阅读文件中的注释内容，避免因显示不匹配导致的错误。
需要注意的是，希冀采用UTF-8编码格式，部分PC下载的参考源码中的中文提示，如果取消注释会显示乱码，
可以通过textbook另存时选择ANSI编码来解决。此操作不影响考题需要提交的Point.cpp文件！
【评分标准】需能够“严格”匹配希冀平台的预期输出框显示的结果，具体的请查看示例代码中的注释说明！*/

// main.cpp 由于希冀后端测试平台的预期输出显示逻辑有别于本地IDE，所以部分显示代码或循环逻辑被注释掉。在本地调试时，可以放出被注释部分，便于循环调试
#include <iostream>//引入iostream头文件
#include "Point.h"//引入题目自定义的Point.h声明文件
//因不同IDE的编译器环境差异，可考虑使用下列2种调试语句，解决编译器告警或报错问题
//g++ -std=c++11 main.cpp Shape.cpp -o main
//#pragma GCC diagnostic error "-std=c++11"
//由于希冀采用UTF-8编码，如果下载参考源代码到本地后出现中文显示乱码，可以用textbook另存一遍工程文件，在另存时选择ANSI编码。
//请务必注意，由于输出包含"Value:"作为提示,因此提供Point.cpp中用作实现显示输出的语句，请在编写Point.cpp时采用下列代码逻辑进行输出显示：
//void point::display() const {
//std::cout << "Value: " << value << std::endl;
//}
int main() {
    int initialValue;//由于希冀平台预期输出需要多组数据，因此不采用填空题设置初始值为1的逻辑，而是改为手动键入
    //std::cout << "请输入初始值: ";
    std::cin >> initialValue;

    point myPoint(initialValue);

    char operation;
    //char continueFlag;

    //do {
        //std::cout << "请输入操作 (a: 加, s: 减): ";
    std::cin >> operation;

    if (operation == 'a') {
        //std::cout << "前缀递增后结果：" << std::endl;
        (++myPoint).display();

        //std::cout << "后缀递增后结果：" << std::endl;
        myPoint++;
        myPoint.display();
    }
    else if (operation == 's') {
        // std::cout << "前缀递减后结果：" << std::endl;
        (--myPoint).display();

        // std::cout << "后缀递减后结果：" << std::endl;
        myPoint--;
        myPoint.display();
    }
    else {
        std::cout << "无效的操作" << std::endl;
    }

    //std::cout << "是否继续? (y: 是, n: 否): ";
    //std::cin >> continueFlag;

//} while (continueFlag == 'y');不再采用循环逻辑，以严格匹配希冀平台期望输出的显示逻辑

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
