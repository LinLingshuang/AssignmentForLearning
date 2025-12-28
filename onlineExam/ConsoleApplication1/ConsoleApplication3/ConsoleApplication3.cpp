/*4. 员工类Employee 和 部门类Department 的组合与前向引用
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
*/
#define _CRT_SECURE_NO_WARNINGS  //使用微软Visual Studio 编译器时需要的开关
#include <iostream>
#include <cstring>
#include<string>
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
                    employees[j] = employees[j + 1];// 空1

                employees[empCount - 1] = nullptr; // 最后一个元素置空

                empCount--;// 空2
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

    (*d).addEmployee(this);// 空3
}
// 获取员工姓名
const char* Employee::getName() const
{

    return name;// 空4
}
// 改变员工所属的部门，先从旧部门移除，然后添加到新部门
void Employee::changeDepartment(Department* newDept)
{
    if (!newDept)
    {
        throw std::invalid_argument("New department pointer cannot be null");
    }

    (*dept).removeEmployee(this);// 空5  

    (*newDept).addEmployee(this);
}

char* operator>>(istream& i, char*a) {
    string temp;
    cin >> temp;
    for (int i = 0; i < temp.length(); i++) {
        a[i] = temp[i];
    }
    a[temp.length()] = '\0';
    return a;
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
