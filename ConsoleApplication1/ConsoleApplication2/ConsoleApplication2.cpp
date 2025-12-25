// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
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

4. 员工类Employee 和 部门类Department 的组合与前向引用
【问题描述】

请补充完整下面空白的程序语句。

本题定义了两个类： 员工类Employee 和 部门类Department，

员工类包含姓名、部门指针、构造函数、改变员工所属部门方法、获取姓名方法。

部门类包含部门名称、部门的员工数组、员工数量、构造函数、添加员工方法、移除员工方法；

添加部门员工时，如果部门的员工已达到上限（10人），将不会添加新员工。

移除部门员工时，如果员工不在部门中，将输出警告信息。

【输入形式】

字符串类型的员工名称

【输出形式】

字符串类型的部门名称和所属员工名称列表

【样例输入】

张三

【样例输出】

Employees in department HR :

Alice

Bob

张三

Employees in department HR :

Alice

Bob

Employees in department Tech :

张三

【样例说明】

先输出HR部门的员工列表，包含Alice、Bob和新加入的张三；

然后将张三从HR部门移动到Tech部门，输出HR部门的员工列表包含Alice和Bob， 输出Tech部门的员工列表包含张三。

【评分标准】

#define _CRT_SECURE_NO_WARNINGS  //使用微软Visual Studio 编译器时需要的开关
#include <iostream>
#include <cstring>
#include <stdexcept> // 为了使用 std::invalid_argument 的异常定义
using namespace std;

class Department; // 前向声明，告诉编译器 Department 类的存在

// 定义 Employee 类
class Employee
{
private:
    char name[50];
    class Department* dept;

public:
    Employee(const char* n, class Department* d);     // 构造函数，实现放在 Department 定义后
    void changeDepartment(class Department* newDept); // 改变所属部门，实现放在 Department 定义后
    const char* getName() const;                      // 获取员工姓名，实现放在 Department 定义后
};

// 定义 Department 类，此时 Employee 类的完整定义已可见
class Department
{
private:
    char departName[50];     // 部门名称
    Employee* employees[10]; // 每个部门最多容纳10人
    int empCount;            // 部门当前员工数量

public:
    Department(const char* n) : empCount(0)
    {
        strncpy(departName, n, sizeof(departName) - 1);
        departName[sizeof(departName) - 1] = '\0'; // 防止溢出
    }

    // 向当前部门添加一名员工,部门最大员工数量为10人
    void addEmployee(Employee* e)
    {
        if (empCount < 10)
            employees[empCount++] = e;
    }

    // 从当前部门移除一名员工,如果员工不存在，则输出警告信息
    void removeEmployee(Employee* e)
    {
        for (int i = 0; i < empCount; ++i)
        {
            if (employees[i] == e)
            {
                for (int j = i; j < empCount - 1; ++j)

                    // 空1

                    employees[empCount - 1] = nullptr; // 最后一个元素置空

                // 空2
                return;
            }
        }
        cerr << "Warning: Employee not found in department" << endl;
    }

    void printEmployees()
    {
        cout << "Employees in department " << departName << ":" << endl;
        for (int i = 0; i < empCount; ++i)
            cout << employees[i]->getName() << endl;
    }
};

// Employee 类的构造函数实现，初始化成员变量name和dept，并添加到部门
Employee::Employee(const char* n, Department* d) : dept(d)
{
    if (!d)
    {
        throw std::invalid_argument("Department pointer cannot be null");
    }
    strncpy(name, n, sizeof(name) - 1);
    name[sizeof(name) - 1] = '\0';

    // 空3
}
// 获取员工姓名
const char* Employee::getName() const
{

    // 空4
}
// 改变员工所属的部门，先从旧部门移除，然后添加到新部门
void Employee::changeDepartment(Department* newDept)
{
    if (!newDept)
    {
        throw std::invalid_argument("New department pointer cannot be null");
    }

    // 空5  
}

int main()
{
    char* inputName = new char[50];
    cin >> inputName;

    Department hr("HR");
    Department tech("Tech");

    Employee alice("Alice", &hr);
    Employee bob("Bob", &hr);
    Employee newEmploy(inputName, &hr);

    hr.printEmployees(); // 输出 HR部门的员工

    newEmploy.changeDepartment(&tech); // 将 newEmploy 从 HR 部门移动到 Tech 部门
    hr.printEmployees();            // 输出 HR部门的员工
    tech.printEmployees();          // 输出 Tech部门的员工

    cin.ignore();
    return 0;
}

3. 动态数组类实现深复制
【问题描述】

请补充完整下面空白的程序语句。

本题要完成一个动态整型数组类 DynamicArray 的定义，它要支持构造函数、深复制构造函数、赋值运算符重载、析构函数以及基本的set和print方法。

动态数组的元素个数不超过50，元素类型为int，数组元素数据存储在动态创建的int型数组中，数组元素值初始化为0。



构造函数接收一个整数参数，表示数组的大小。

深复制构造函数接收一个 DynamicArray 对象的引用，实现深复制。

赋值运算符重载实现深复制。

析构函数释放动态数组所占用的内存。

set方法接收两个整数参数，表示要设置的数组元素的索引和值。

print方法输出数组的所有元素值。



【输入形式】

从键盘输入数组的大小和元素值。



【输出形式】

输出数组1和数组2的所有元素值。



【样例输入】

3

10 20 30



【样例输出】

Array 1:10 20 30

Array 2 : 10 20 30



【样例说明】

输入数组大小为3，元素值分别为10、20、30。输出数组1和数组2的元素值都为10、20、30。

#include <iostream>
using namespace std;

class DynamicArray
{
private:
    int* data; // 动态数组数据元素指针
    int size;  // 动态数组大小

public:
    DynamicArray(int s)
    {
        size = s;
        data = new int[s];
        for (int i = 0; i < s; ++i)
            data[i] = 0;
    }

    DynamicArray(const DynamicArray& other)
    {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; ++i)

            // 空1
    }

    DynamicArray& operator=(const DynamicArray& other)
    {
        if (this == &other)
            return *this;

        delete[] data;
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; ++i)

            // 空2

                // 空3
    }

    ~DynamicArray()
    {

        // 空4
    }

    void set(int index, int val)
    {
        if (index >= 0 && index < size)

            // 空5
    }

    void print() const
    {
        for (int i = 0; i < size; ++i)
            cout << data[i] << " ";
        cout << endl;
    }
};

int main()
{
    int arrSize = 0;
    int arrValue = 0;

    cin >> arrSize;
    if (arrSize < 0 || arrSize > 50)
    {
        cout << "Invalid size" << endl;
        return 1;
    }

    DynamicArray arr1(arrSize);
    for (int i = 0; i < arrSize; i++)
    {
        cin >> arrValue;
        arr1.set(i, arrValue);
    }
    cout << "Array 1:";
    arr1.print();

    DynamicArray arr2 = arr1;
    cout << "Array 2:";
    arr2.print();

    return 0;
}

1.
给出下述程序的执行结果

#include <stdio.h>
long fib(int x)
{
    switch (x)
    {
    case 0: return 0;
    case 1:
    case 2:  return 1;
    }
    return (fib(x - 1) + fib(x - 2));
}
main()
{
    int x = 6;
    printf("%d\n", fib(x));
}

2.
请在下列main.cpp工程文件中，补齐部分注释所提示的功能代码。此文件是一个基于类的继承，进而实现矩形、圆形分别进行周长、面积计算的工程的一部分。主要实现了：基于键盘输入选择不同子类、基于子类基本特性判断输入是否正确、基于键盘输入完成对应子类的周长和面积计算，最后提示通过关键字符来确定是否继续运行。

// main.cpp

#include <iostream> // 引入 iostream 头文件

#include <limits>  // 引入 limits 头文件

#include "Shape.h"

//因不同IDE的编译器环境差异，可考虑使用下列2种调试语句，解决编译器报错问题

//g++ -std=c++11 main.cpp Shape.cpp -o main

//#pragma GCC diagnostic error "-std=c++11"

//部分PC存在字库导入差异，从网上复制代码到本地后会出现中文字符乱码。可用textbook打开工程文件，并再另存时选择ansi编码格式，来解决该问题。希冀平台默认保存为UTF-8。



int main() {

    char continueChar;

    do {


        // 如果复制注释中的提示语句，请务必检查符号是否是中文。改行是一个指向Shape类的指针，并将指针shape初始化为0。强调，由于不同IDE的编译器差异，为了避免报错，这里牺牲特性，使用0而不使用nullptr。不要遗漏";"。

        char shapeType;



        std::cout << "请选择形状类型 (R for Rectangle, C for Circle): ";

        std::cin >> shapeType;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');



        if (shapeType == 'R' || shapeType == 'r') {//通过键盘键入选择Rectangle类

            double width, height;


            {     //结合前后语句，这里显然是while判断，来实现无限循环，直到输入符合条件。注意是无限循环，所以条件已明确，且结尾已有"{"，不要重复了！

                std::cout << "请输入矩形的长: ";


                // 获取用户输入的长度。使用C++标准库中的输入流对象语句，对象是height，不要遗漏";"。

                std::cout << "请输入矩形的宽: ";


                // 获取用户输入的宽度。C++标准库中的输入流对象语句，对象是width，不要遗漏";"。



                if (width > height) {

                    std::cout << "错误: 矩形的宽不能大于长，请重新输入！" << std::endl;

                }
                else {


                    // 通过指针，用"new"将输入的值，初始化为Rectangle的2种属性width, height。不要遗漏";"。

                    break;

                }

            }

        }
        else if (shapeType == 'C' || shapeType == 'c') {//通过键盘键入选择Circle类

            double radius;

            std::cout << "请输入圆形的半径: ";

            std::cin >> radius;


            ;// 通过指针，用"new"将输入的值，初始化为Circle的1种属性radius。不要遗漏";"。

        }
        else {

            std::cout << "无效的形状类型!" << std::endl;

            continue;

        }



        // 如果shape不为0，调用display并删除对象

        if (shape) {

            shape->display();


            // 通过delete删除指针的方式，释放动态分配的内存，不要遗漏";"。

        }




        // 使用C++标准库中的输出流对象语句，提示用户是否继续，显示内容为"是否继续? (y for yes, n for no): "，不要遗漏";"。

        std::cin >> continueChar;


        // 清除输入缓冲区。首先使用C++标准库中用于处理标准输入的对象语句。其次通过.ignore()忽略输入流中的字符。第三是使用std::numeric_limits的模板类静态成员函数，用于获取类型std::streamsize（表示流大小的类型）能表示的最大值"max()"，并将它用作.ignore()函数的第一个参数，表示要忽略的最大字符数。最后用终止字符"\n"作为.ignore()函数的第二个参数（使用字符时注意格式为'\n'），使得.ignore()函数停止忽略字符，即使还没有达到指定的最大字符数。不要遗漏";"。



    } while (continueChar == 'y' || continueChar == 'Y');



    return 0;

}



3.
请在下列抽象类Shape的声明文件Shape.h的代码中，补齐部分注释要求达成的内容，实现子类Rectangle和Circle对父类Shape的继承，和对应矩形、圆形的面积、周长计算：

// Shape.h

#ifndef SHAPE_H

#define SHAPE_H

#include <iostream>

// 定义Shape类

class Shape {

public:

    // 纯虚函数：计算面积和周长


// 如果复制注释中的提示语句，请务必检查符号是否是中文。请写出如何构建纯虚函数的代码。此行为面积，Area，注意大小写。方法为使用get函数getArea()，类型为double，不要遗漏";"


//请写出如何构建纯虚函数的代码。此行为周长，Perim，注意大小写。方法为使用get函数getPerim()，类型为double,不要遗漏";"



    // 纯虚函数：显示名称

    virtual void display() const = 0;



    // 虚函数声明


//请写出对应Shape类的虚函数声明语句，注意不要遗漏"{}"，且注意该行不是";"结尾！

};



// 定义Rectangle类，继承Shape类

{//提示已告知此处是Rectangle子类，用于继承Shape类，则此行是使用class来实现对public Shape的继承方法，同时注意行末已有"{"，所以不要重复

private:

    double width;

    double height;



public:

    // 构造函数和析构函数


//既然定义的是Rectangle子类，那此行就是Rectangle子类的构造函数，不要遗漏";"


//往下查看set函数可以发现，Rectangle子类用于计算的是"w"和"h"，且类型为double，不要遗漏";"


//Rectangle子类的析构函数，注意不要遗漏"{}"，且注意该行不是";"结尾！



    // get函数

    double getWidth() const;

    double getHeight() const;



    // set函数

    void setWidth(double w);

    void setHeight(double h);



    // 实现抽象方法


//面积。第三行的显示中已有实现方法的提示，即使用"override"，让Rectangle子类重载Shape基类中的getArea()函数，类型仍然是double，不要遗漏";"


//周长。方法同上一行。

    void display() const override;

};



// 定义Circle类，继承Shape类

{//对照Rectangle子类，使用class实现Circle子类对public Shape的继承。注意事项同上。

private:

    double radius;



public:

    // 构造函数和析构函数


//对照Rectangle子类的实现方法，实现Circle子类的构造函数，不要遗漏";"


//下面set函数已提示为"double r"，不要遗漏";"


//对照Rectangle子类的实现方法，实现Circle子类的析构函数。注意事项同上。



    // get函数

    double getRadius() const;



    // set函数

    void setRadius(double r);



    // 实现抽象方法


//面积。对照Rectangle子类的实现方法，实现Circle子类的面积计算，不要遗漏";"


//周长。对照Rectangle子类的实现方法，实现Circle子类的周长计算，不要遗漏";"

    void display() const override;

};



#endif // SHAPE_H



4.
在C++中，如果派生类的构造函数需要给基类的构造函数传递参数，应在派生类构造函数的
部分进行初始化。

5.
设有以下结构体定义和变量声明：

struct Student {

    int id;

    char name;

} stu, * p = &stu;

若要通过指针 p 给成员 id 赋值100，正确的语句是
。



6.
以下递归函数用于计算数组元素的累加和，请补全空缺部分。

int sumArray(int arr[], int n) {
    if (n <= 0) return 0;
    return
        ;
}


7.
假定指针变量 p 定义为 int* p = new int; ，要释放 p 所指向的动态内存，应使用语句
。

8.
在C++中，重载前置自增运算符（++）和后置自增运算符（++）的函数原型是不同的。

请补全下面的类中，用于重载后置自增运算符的函数声明。

注意区分前置和后置的语法差异。

class Counter {
private:
    int count;
public:
    Counter() : count(0) {}

    // 前置自增: ++obj
    Counter& operator++() {
        ++count;
        return *this;
    }

    // 请补全后置自增的函数声明 (obj++)

    ;

    int getCount() const { return count; }
};

// 请补全后置自增的函数定义
{
    Counter temp = *this; // 保存当前状态
    ++count;            // 执行自增
    return temp;        // 返回自增前的状态
}


9.
请补齐下列point.h声明文件的缺失代码，实现注释中要求的功能。该文件是一个实现类重载的工程的声明文件，主要进行类的声明、函数的声明。

// point.h

 //  如果复制注释中的提示语句，请务必检查符号是否是中文。防止头文件重复包含的预处理指令，目标宏定义是下一行中定义的POINT_H。因为源码程序中创建了名为POINT_H的宏定义用于简化操作，考虑到真实开发环境中的协同复杂性，这里就引入了防重复操作，作为考核点。

#define POINT_H



#include <iostream>  // 引入输入输出流头文件



// 定义Point类

class Point {

private:

    int value;  // 存储点的值

    static int initialValue;  // 静态属性，初始值



public:

    // 构造函数

    Point();  // 默认构造函数

    Point(int val);  // 带参数的构造函数



    // 虚析构函数


//注意是"~Point()"，并且该行是"{}"结尾。如果复制注释中的提示语句，请务必检查符号是否是中文



    // get函数，获取点的值

    int getValue() const;



    // set函数，设置点的值

    void setValue(int val);



    // 前缀自增运算符重载


//使用operator重载操作符函数来实现Point的前缀自增，该函数签名中要有空括号来表示前缀形式的自增操作。注意，这是.h声明接口文件，所以只需声明函数签名。结尾不要遗漏";"



    // 后缀自增运算符重载


//使用operator重载操作符函数来实现Point的后缀自增，该函数签名中不仅是括号，括号中要带有单个int参数，来作为后缀操作符重载的标志，但int实际参数值并不使用。且这是.h声明接口文件，因此只需声明函数签名。结尾不要遗漏";"



    // 前缀自减运算符重载


 //同前缀自增



    // 后缀自减运算符重载


//同后缀自增

    // 显示函数，显示点的值

    void display() const;



    // 友元函数，用于输入和输出


// 输出友元函数。使用标准库中的输出流对象语句，实现返回一个指向输出流的引用（类型是ostream），使用operator操作符重载函数，重载 << 操作符。输出流对象的引用是函数的第一个参数（std::ostream& os），常量引用类型的Point对象是函数的第二个参数（const Point& p），也是需要输出的对象。不要遗漏";"


// 输入友元函数。参考输出友元函数的实现方法，进行引用和参数的替换，如"istream"\"std::istream& is"。另，友元函数的第二个参数是引用类型的Point对象（Point& p），它是需要输入数据的对象。不要遗漏";"

};



#endif // POINT_H



10.
补齐下列main.cpp工程中的代码，使之完成注释中要求的功能。该文件是一个类的重载工程的一部分，主要实现通过键盘输入来选择加法或减法、通过operation操作符实现前缀和后缀的自增自减、基础的信息交互与显示。

// main.cpp

#include <iostream>

//引入自定义的point.h类头文件，注意大小写



int main() {


    // 创建一个point对象p。注意大小写，注意结尾";"

    char operation;

    char continueChar;



    do {

        std::cout << "请选择操作 (a for add, s for subtract): ";

        std::cin >> operation;



        if (operation == 'a') {

            std::cout << "初始值: ";

            p.display();


            // 前缀自增。对象是前面已创建的对象p，注意结尾";"

            std::cout << "前缀自增后: ";

            p.display();


            // 后缀自增。对象是前面已创建的对象p，注意结尾";"

            std::cout << "后缀自增后: ";

            p.display();

        }
        else if (operation == 's') {

            std::cout << "初始值: ";

            p.display();


            // 前缀自减。对象是前面已创建的对象p，注意结尾";"

            std::cout << "前缀自减后: ";

            p.display();


            // 后缀自减。对象是前面已创建的对象p，注意结尾";"

            std::cout << "后缀自减后: ";

            p.display();

        }
        else {


            // 如果输入的是无效操作，提示错误信息。提示内容为"无效的操作!"。需使用C++标准库中输出流对象语句，并使用操作符"std::endl"作为结尾，在输出后插入换行符并刷新缓冲区，防止缓冲区溢出

        }



        std::cout << "是否继续? (y for yes, n for no): ";

        std::cin >> continueChar;



    }
    // 如果用户输入的是 'y' 或 'Y'，继续循环。显然需要使用while来进行循环判定，同时在main函数的第三行定义了char类型的变量continueChar，这里就可以用作检查键盘键入是否是'y' 或 'Y'的一致性判断，由于2种输入都可能继续循环，需要使用" || "逻辑



    return 0;

}

1.	已提交
在c++中，表达式 5 / 2 的结果是 2.5


正确

错误
2.	已提交
对于 std::string 类型的变量 s，执行 s.substr(1, 3) 后，返回的是从下标为 1 的字符开始，长度为 3 的子串。


正确

错误
3.	已提交
在多重继承中，如果两个基类都有一个同名的虚函数，派生类必须重写（覆盖）这个函数，否则会产生二义性错误。


正确

错误
4.	已提交
在 C++ 中，NULL 和 nullptr 是完全等价的，可以随意互换使用，且 nullptr 的类型是 void* 。


正确

错误
5.	已提交
如果派生类的析构函数是虚函数，那么基类的析构函数也必须是虚函数，否则会导致编译错误。


正确

错误
单选题
1.
在模板参数列表中，typename 和 class 关键字的描述，错误的是（    ）。答案： _____
A.在声明模板类型参数时，typename 和 class 在大多数情况下可以互换
B.当需要表达“T 是一个类类型”且涉及嵌套依赖类型时，必须使用 typename
C.模板模板参数（Template Template Parameter）中，必须使用 class 关键字
D.  typename 更符合“泛型”的语义，建议优先使用
2.
关于函数模板的实例化（Instantiation），下列说法正确的是（    ）。答案： _____
A.函数模板在编译时（Compilation）就会为所有可能的类型生成代码
B.函数模板在链接时（Linking）根据调用处生成具体代码
C.函数模板在编译时，仅在遇到具体调用时才会生成对应类型的实例代码
D.函数模板的代码生成发生在运行时（Runtime）
3.
关于模板中的友元函数（Friend Function），下列说法正确的是（    ）。答案： _____
A.类模板中的友元函数自动成为函数模板
B.如果想让一个非模板函数成为所有模板实例的友元，必须在类外单独声明
C.可以在类模板内部定义友元函数，使其针对每个模板实例生成对应的版本
D.模板类不能拥有友元函数
4.
关于空类（Empty Class）的大小，以下说法正确的是（    ）。答案： _____
A.空类的大小为 0 字节
B.空类的大小为 1 字节，用于占位以区分不同对象
C.空类的大小取决于编译器，可能为 0 或 1
D.只有包含虚函数的空类大小才为 1 字节
5.
关于dynamic_cast，下列说法错误的是（    ）。答案： _____
A.用于运行时类型识别
B.可以用于向下转型
C.转换失败返回NULL
D.转换失败抛出异常
6.
关于const在函数参数中的作用，下列说法错误的是（    ）。答案： _____
A.  void func(const int* p) 表示不能在函数内通过指针 p 修改其所指向的值。
B.  void func(int* const p) 表示指针p本身不能被重新赋值指向其他地址。
C.  void func(const int& x) 通常用于传递大对象且不希望在函数内修改原值，同时避免拷贝开销。
D.如果函数参数是const的，那么传入的实参也必须是const类型的变量。
7.
关于new与malloc的区别，以下说法错误的是（    ）。答案： _____
A.new是操作符，malloc是函数
B.new分配内存后会自动调用构造函数，malloc仅分配原始内存
C.new分配失败时返回NULL，malloc抛出bad_alloc异常
D.new不需要强制类型转换，malloc返回void * 需要强制转换
8.
关于this指针，下列描述错误的是（    ）。答案： _____
A.this指针是一个指向当前对象的常量指针
B.静态成员函数中可以使用 this 指针
C.  this 指针作为隐含参数传递给非静态成员函数
D.在成员函数中返回对象本身通常使用 * this
9.
关于静态成员变量，下列说法正确的是（    ）。答案： _____
A.静态成员变量必须在类体内初始化
B.静态成员变量属于类，不属于任何对象
C.静态成员变量不能通过对象访问
D.静态成员函数不能访问静态成员变量
10.
如果希望在多次函数调用之间保持局部变量的值，应该使用哪个关键字修饰该变量？（    ）。答案： _____
A. static
B. const
C. extern
D. auto
11.
以下关于函数声明和定义的说法，错误的是（    ）。答案： _____
A.函数声明通常放在头文件或主函数之前，用于告诉编译器函数的名字、返回类型和参数列表。
B.函数定义包含了函数的具体实现（函数体）。
C.如果函数定义写在主函数 main 之前，可以省略函数声明。
D.函数声明和函数定义的参数列表可以不一致，编译器会自动匹配。
12.
关于函数的返回值，下列描述正确的是（    ）。答案： _____
A.一个函数可以有多个 return 语句，但只能返回一个值（除非使用结构体或引用等特殊手段）。
B.如果函数的返回类型是 void，则函数体内不能出现 return 语句。
C.函数返回值的类型由 return 语句中表达式的类型决定，与函数定义的返回类型无关。
D.函数执行完所有语句后，如果不写 return，默认返回 0。
13.
若希望在函数内部修改实参的值，应使用哪种参数传递方式？（    ）答案： _____
A.值传递
B.指针传递
C.引用传递
D.B和C都可以
14.
关于“值传递”，下列说法正确的是（    ）。答案： _____
A.形参是实参的别名，对形参的操作就是对实参的操作。
B.形参是实参的拷贝，修改形参不会影响实参的值。
C.形参是指向实参地址的指针。
D.值传递比引用传递效率更高，因为不需要创建副本。
15.
关于函数重载的描述，下列错误的是（    ）。答案： _____
A.重载函数的函数名必须相同。
B.重载函数的参数列表（参数个数、类型或顺序）必须不同。
C.重载函数的返回类型必须不同。
D.函数重载允许使用相同的函数名来处理不同类型或数量的数据。
16.
以下哪个选项正确地定义了一个名为 max 的内联函数？（    ）。答案： _____
A. inline int max(int a, int b) { return a > b ? a : b; }
B. int inline max(int a, int b) { return a > b ? a : b; }
C. int max(int a, int b) inline { return a > b ? a : b; }
D. #inline int max(int a, int b) { return a > b ? a : b; }
17.
以下代码中，哪一个是正确的虚析构函数声明：（    ）。答案： _____
A. virtual ~ClassName() {}
B. ~ClassName() virtual {}
C. virtual ~ClassName() const {}
D. ~ClassName() const virtual {}
多选题
1.
下列关于运算符重载的叙述中，错误的是(_____)
A.运算符重载可以改变运算符的优先级和结合性。
B.可以通过友元函数重载赋值运算符 = 。
C.下标运算符[] 只能作为类的成员函数重载。
D.重载的运算符必须至少有一个操作数是用户自定义类型（类类型）。
2.
下列关于抽象类和接口的描述，正确的是 （  _____ ）
A.包含纯虚函数的类是抽象类，不能直接实例化对象。
B.抽象类的派生类如果不实现所有的纯虚函数，该派生类仍然是抽象类。
C.通过定义只包含纯虚函数的类来实现类似“接口”的机制。
D.纯虚函数的定义形式是 virtual void func() {}。
3.
关于 静态成员（static），下列叙述正确的是 （  _____ ）
A.静态数据成员必须在类外进行定义和初始化。
B.静态成员函数可以直接访问类中的非静态数据成员。
C.静态成员函数没有 this 指针。
D.静态数据成员不属于某个具体的对象，而是属于整个类。
4.
下列关于常量（const）和引用的叙述中，正确的是 （  _____ ）
A. const 数据成员只能通过构造函数的初始化列表进行初始化。
B.常对象只能调用常成员函数，不能调用普通的成员函数。
C.引用在定义时必须初始化，且一旦绑定就不能再指向其他变量。
D.指针常量（如 int* const p）定义后，其指向的地址可以改变，但指向的内容不能改变。
填空题

11. 学生成绩排序
【问题描述】

假设用C++定义了一个学生类，包含如下字段：



class Student {
private:
    int id;         // 学号
    int chinese;    // 语文
    int math;       // 数学
    int english;    // 英语
    int physics;    // 物理
    int chemistry;  // 化学
    int biology;    // 生物
    int total;      // 总分
public:
    Student(int id, int chinese, int math, int english, int physics, int chemistry, int biology);
};



任务要求：

1. 补全Student类的构造函数，在构造函数中计算并初始化total字段。

2. 编写一个main函数，实现以下功能：

￮ 接收用户输入的学生信息，并将学生信息存入合适的STL容器中。

￮ 根据用户的选择进行排序：输入1, 按照学号升序排序并输出学生信息; 输入2, 按照总分降序排序并输出学生信息。

￮ 用户输入的语文、数学和英语的分数介于0~150之间，物理、化学、生物的分数介于0~100之间。如果学生的任一成绩不在合法范围内，则该学生总成绩无效，在排序输出时，该学生信息应置于最后，并在总分列标记“invalid”。

￮ 总成绩“invalid”的学生信息排在最后面（不论是按照学号排列，还是按照总分排列），若有多个学生总分无效，总分无效部分按照稳定排序方式进行（即：排序前顺序排列）

￮ 学生成绩合法性检查可在Student类的构造函数中实现。

￮ 建议：使用std::sort进行排序，编写函数对象或lambda表达式完成自定义排序逻辑。

￮ 可以适当在Student类中增加字段；可以适当改造构造函数；可以适当添加Student类的成员函数。





【输入形式】

• n个学生的测试用例由n + 2行输入。第一行，表示学生的数量n；接下来第2~（n + 1）行表示学生的信息；第n + 2行，表示排序方式（1表示按学号排序，2表示按总分排序）。

• 学生信息由“学号 语文 数学 英语 物理 化学 生物”等7个整型数字组成，学号编号为4位数字，第一位数字不为0。


【输出形式】


学号 : 语文 数学 英语 物理 化学 生物 总分

注意，

• 学号后面是英文状态下的“ : ",后面有空格（space键）；

• 分数之间有空（space键）

• 总分后面没有空格，但有回车换行符。



【样例输入】

输入样例1：



3
1001 85 80 78 90 85 80
1002 90 95 88 86 89 90
1003 75 70 65 68 72 60
2





输入样例2：



3
1001 85 80 78 90 85 80
1002 180 95 88 86 89 90
1003 75 70 65 68 72 60
2






【样例输出】

输出样例1：



1002: 90 95 88 86 89 90 538
1001 : 85 80 78 90 85 80 498
1003 : 75 70 65 68 72 60 410







输出样例2：

1001: 85 80 78 90 85 80 498
1003 : 75 70 65 68 72 60 410
1002 : 180 95 88 86 89 90 invalid




【样例说明】

暂无


【评分标准】

每个测试用例2分，共10分。

测试用例包括空输入或0名学生的情况。



【问题描述】
编写一函数expand(s1, s2)，用以将字符串s1中的缩记符号在字符串s2中扩展为等价的完整字符，例如将a - d扩展为abcd。该函数可以处理大小写字母和数字，并可以处理a - b - c、a - z0 - 9与 - a - z等类似的情况。在main函数中测试该函数：从键盘输入包含缩记符号的字符串，然后调用该函数进行扩展，输出扩展结果。

注意：

待扩展字符串中有可能包含空格，例如：a - d x - z应扩展成：abcd xyz。所以读入待扩展字符串时，应能够读入包含空格的字符串。

只要缩记符号 - 之后的字符比之前的字符的ASCII码值大，就要将它们之间的所有字符扩展出来，例如：Z - a之间的字符也要扩展出来；

特殊情况：a - b - c将被扩展为：abc。a - a将被扩展为：a - a。

【输入形式】
从键盘输入包含扩展符的字符串
【输出形式】
输出扩展后的字符串
【输入样例】

a - c - u - B
【输出样例】

abcdefghijklmnopqrstu - B
【样例说明】
扩展输入a - c - u为：abcdefghijklmnopqrstu，而B比u值小，所以无法扩展，直接输出。
【问题描述】
编写一个程序，从一个文件中读入单词（即：以空格或回车换行分隔的字符串），并对单词进行排序，删除重复出现的单词，然后将结果输出到另一个文件中。
【输入形式】
源文件名和目标文件名在执行时作为程序命令行参数输入，例如若程序名为sort，
源文件名和目标文件名分别为sort.in和sort.out，则命令行为：sort  sort.in  sort.out。
程序将从当前目录下sort.in文件中读入单词。
【输出形式】
对单词进行排序，删除重复出现的单词，然后将结果输出到文件sort.out中。
【输入样例】
假如sort.in文件内容如下：

rrr  sss  aaa  bbb  ccc   ddf  aaa  dd
【输出样例】
sort.out文件内容为：

aaa bbb ccc dd  ddf  rrr sss
【样例说明】
读入文件sort.in，做适当的排序，并删除重复出现的单词，输出到文件sort.out

编程题
6. 时间类Time的编写
【问题描述】

编写一个程序，定义一个时间类Time，包含三个属性： hour, minute 和 second

要求通过运算符重载实现如下功能 :
时间输入输出(>> 、 << )；

时间增加减少若干(+= 、 -= )，例：Time& operator+=(const Time&); Time& operator-=(const Time&)；

时间前、后自增加 / 减少1秒(++、--)，前自增例：Time & operator++(); 后自增例：Time operator++(int)；

【输入形式】

输入固定为两个Time实例(time1，time2), 每个实例占一行；

Time实例输入格式为：hour minute second。

【输出形式】

Time实例输出格式为：hour : minute:second；

每个输出实例占一行。

依次输出以下表达式的值
time1 += (time2++)

time1 -= time2

++time2

time2 += (time1--)

--time1

time2 -= time1

【样例输入】

21 10 35
10 15 25
【样例输出】

07:26 : 00
21 : 10 : 34
10 : 15 : 27
07 : 26 : 01
21 : 10 : 32
10 : 15 : 29
【样例说明】

不要显示多余的提示信息，避免输出判定错误。

输出结束后不要输出任何内容，包括空格和换行。

注意判断输出信息是否符合要求。

编程题
4. 声明一个Employee类，包括name、ID、Salary等属性，以及chan
【问题描述】

声明一个Employee类，包括name、ID、Salary等属性，以及chang_name()和display()等函数，输入ID，可以更改该ID对应的姓名

【输入形式】

ID
【输出形式】

名字占用8个字符，ID占用3个字符，Salary占用10个字符

所有属性
【样例输入】

1

Betty
【样例输出】

Betty, 1, $5000

Bob, 2, $5500

Charlie, 3, $6000

David, 4, $6500

Eve, 5, $7000

【样例说明】
【评分标准】

