/*
2.
请在下列main.cpp工程文件中，补齐部分注释所提示的功能代码。
此文件是一个基于类的继承，进而实现矩形、圆形分别进行周长、面积计算的工程的一部分。
主要实现了：基于键盘输入选择不同子类、基于子类基本特性判断输入是否正确、基于键盘输入完成对应子类的周长和面积计算，
最后提示通过关键字符来确定是否继续运行。
*/
// main.cpp

#include <iostream> // 引入 iostream 头文件

#include <limits>  // 引入 limits 头文件

#include "Shape.h"

//因不同IDE的编译器环境差异，可考虑使用下列2种调试语句，解决编译器报错问题

//g++ -std=c++11 main.cpp Shape.cpp -o main

//#pragma GCC diagnostic error "-std=c++11"

//部分PC存在字库导入差异，从网上复制代码到本地后会出现中文字符乱码。
// 可用textbook打开工程文件，并再另存时选择ansi编码格式，来解决该问题。希冀平台默认保存为UTF-8。
int main() {

    char continueChar=0;

    do {
        // 如果复制注释中的提示语句，请务必检查符号是否是中文。
        Shape* shape = 0;// 改行是一个指向Shape类的指针，并将指针shape初始化为0。
        // 强调，由于不同IDE的编译器差异，为了避免报错，这里牺牲特性，使用0而不使用nullptr。不要遗漏";"。

        char shapeType;
        std::cout << "请选择形状类型 (R for Rectangle, C for Circle): ";
        std::cin >> shapeType;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (shapeType == 'R' || shapeType == 'r') {//通过键盘键入选择Rectangle类

            double width, height;
            while(1){     //结合前后语句，这里显然是while判断，来实现无限循环，直到输入符合条件。
                          //注意是无限循环，所以条件已明确，且结尾已有"{"，不要重复了！
                std::cout << "请输入矩形的长: ";
                std::cin >> height;// 获取用户输入的长度。使用C++标准库中的输入流对象语句，对象是height，不要遗漏";"。
                std::cout << "请输入矩形的宽: ";
                std::cin >> width;// 获取用户输入的宽度。C++标准库中的输入流对象语句，对象是width，不要遗漏";"。
                if (width > height) {
                    std::cout << "错误: 矩形的宽不能大于长，请重新输入！" << std::endl;
                }
                else {
                    shape = new Rectangle(width, height);// 通过指针，用"new"将输入的值，初始化为Rectangle的2种属性width, height。不要遗漏";"。
                    break;
                }
            }
        }
        else if (shapeType == 'C' || shapeType == 'c') {//通过键盘键入选择Circle类

            double radius;
            std::cout << "请输入圆形的半径: ";
            std::cin >> radius;
            shape = new Circle(radius);// 通过指针，用"new"将输入的值，初始化为Circle的1种属性radius。不要遗漏";"。

        }
        else {

            std::cout << "无效的形状类型!" << std::endl;

            continue;

        }
        // 如果shape不为0，调用display并删除对象

        if (shape) {

            shape->display();
            delete shape;// 通过delete删除指针的方式，释放动态分配的内存，不要遗漏";"。
        }
        std::cout << "是否继续? (y for yes, n for no):";// 使用C++标准库中的输出流对象语句，提示用户是否继续，显示内容为"是否继续? (y for yes, n for no): "，不要遗漏";"。
        std::cin >> continueChar;
        // 清除输入缓冲区。首先使用C++标准库中用于处理标准输入的对象语句。
        // 其次通过.ignore()忽略输入流中的字符。第三是使用std::numeric_limits的模板类静态成员函数，
        // 用于获取类型std::streamsize（表示流大小的类型）能表示的最大值"max()"，并将它用作.ignore()函数的第一个参数，
        // 表示要忽略的最大字符数。最后用终止字符"\n"作为.ignore()函数的第二个参数（使用字符时注意格式为'\n'），
        // 使得.ignore()函数停止忽略字符，即使还没有达到指定的最大字符数。不要遗漏";"。
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (continueChar == 'y' || continueChar == 'Y');
    return 0;
}


