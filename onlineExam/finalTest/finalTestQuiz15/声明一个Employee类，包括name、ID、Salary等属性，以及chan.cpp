/*15. 声明一个Employee类，包括name、ID、Salary等属性，以及chan
【问题描述】
声明一个Employee类，包括name、ID、Salary等属性，以及chang_name()和display()等函数，输入ID，可以更改该ID对应的姓名
【输入形式】
ID
【输出形式】
名字占用8个字符，ID占用3个字符，Salary占用10个字
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
*/
/*
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class Employee {
private:
    string name;
    int ID;
    double Salary;

public:
    // 构造函数
    Employee(string n = "", int id = 0, double sal = 0.0)
        : name(n), ID(id), Salary(sal) {
    }

    // 更改姓名的函数
    void chang_name(string new_name) {
        name = new_name;
    }

    // 显示信息的函数，按照指定格式输出
    void display() const {
        // 设置名字宽度为8个字符，ID宽度为3个字符，薪水宽度为10个字符
        cout << setw(8) << name << ", "
            << setw(3) << ID << ", "
            << "$" << fixed << setprecision(2) << setw(9) << Salary << endl;
    }

    // 获取ID的函数，用于查找
    int getID() const {
        return ID;
    }

    // 设置信息的函数
    void setInfo(string n, int id, double sal) {
        name = n;
        ID = id;
        Salary = sal;
    }
};

int main() {
    // 创建员工数组并初始化
    vector<Employee> employees(5);

    // 初始化员工数据
    employees[0].setInfo("Alice", 1, 5000.00);
    employees[1].setInfo("Bob", 2, 5500.00);
    employees[2].setInfo("Charlie", 3, 6000.00);
    employees[3].setInfo("David", 4, 6500.00);
    employees[4].setInfo("Eve", 5, 7000.00);

    // 输入要修改的员工ID
    int targetID;
    cin >> targetID;

    // 输入新的姓名
    string newName;
    cin >> newName;

    // 查找并修改对应ID的员工姓名
    bool found = false;
    for (auto& emp : employees) {
        if (emp.getID() == targetID) {
            emp.chang_name(newName);
            found = true;
            break;
        }
    }

    // 输出所有员工信息
    for (const auto& emp : employees) {
        emp.display();
    }

    return 0;
}
*/
#include <iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

class Employee {
public:
    Employee(){}
    Employee(string n,int id,int sal):name(n),ID(id),Salary(sal){}

    void change_name(string n){
        this->name = n;

    }
    void display(){

        cout  << setw(8) << this->name  << setw(3) << this->ID  << setw(10)  << this->Salary << endl;

    }
private:
    string name;
    int ID;
    int Salary;
};


int main()
{
    Employee employees[5];
    employees[0] = Employee("Alice", 1, 5000);
    employees[1] = Employee("Bob", 2, 5500);
    employees[2] = Employee("Charlie", 3, 6000);
    employees[3] = Employee("David", 4, 6500);
    employees[4] = Employee("Eve", 5, 7000);


    string name;
    int id;
    cin >> id >> name;
    employees[id - 1].change_name(name);
    for (int i = 0; i < 5; i++) {
        employees[i].display();
    }

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
