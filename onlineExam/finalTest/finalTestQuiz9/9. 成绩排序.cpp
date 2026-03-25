/*9. 成绩排序
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
    Student (int id, int chinese, int math, int english, int physics, int chemistry, int biology);
};



任务要求：

1. 补全Student类的构造函数，在构造函数中计算并初始化total字段。

2. 编写一个main函数，实现以下功能：

￮ 接收用户输入的学生信息，并将学生信息存入合适的STL容器中。

￮ 根据用户的选择进行排序：输入1,按照学号升序排序并输出学生信息; 输入2, 按照总分降序排序并输出学生信息。

￮ 用户输入的每科分数介于0~100之间。

￮ 学生成绩合法性检查可在Student类的构造函数中实现。

￮ 可以适当在Student类中增加字段；可以适当改造构造函数；可以适当添加Student类的成员函数。





【输入形式】

• n个学生的测试用例由n+2行输入。第一行，表示学生的数量n；接下来第2~（n+1）行表示学生的信息；第n+2行，表示排序方式（1表示按学号排序，2表示按总分排序）。

• 学生信息由“学号 语文 数学 英语 物理 化学 生物”等7个整型数字组成，学号编号为4位数字，第一位数字不为0。


【输出形式】


学号: 语文 数学 英语 物理 化学 生物 总分

注意，

• 学号后面是英文状态下的“:",后面有空格（space键）；

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
1002 0 0 88 86 89 90
1003 75 70 65 68 72 60
2






【样例输出】

输出样例1：



1002: 90 95 88 86 89 90 538
1001: 85 80 78 90 85 80 498
1003: 75 70 65 68 72 60 410







输出样例2：

1001: 85 80 78 90 85 80 498
1003: 75 70 65 68 72 60 410
1002: 0 0 88 86 89 90 353




【样例说明】

暂无


【评分标准】

每个测试用例2分，共10分。

测试用例包括空输入或0名学生的情况。*/

#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<map>
using namespace std;


class Student {
public:
    int id;         // 学号
    int chinese;    // 语文
    int math;       // 数学
    int english;    // 英语
    int physics;    // 物理
    int chemistry;  // 化学
    int biology;    // 生物
    int total;      // 总分
    bool invalid = false;
public:
    Student() {}
    Student(int id, int chinese, int math, int english, int physics, int chemistry, int biology) :
        id(id),              // 学号
        chinese(chinese),    // 语文
        math(math),          // 数学
        english(english),    // 英语
        physics(physics),    // 物理
        chemistry(chemistry),// 化学
        biology(biology)    // 生物      
    {
        total = chinese + math + english + physics + chemistry + biology;
        if (chinese > 150 || math > 150 || english > 150 || physics > 100 || chemistry > 100 || biology > 100 ||
            chinese < 0 || math < 0 || english < 0 || physics < 0 || chemistry < 0 || biology < 0
            )
        {
            invalid = true;
        }
    }

    void show()const {
        if (!invalid) {
            cout << id << ": " << chinese << " " << math << " " << english << " " << physics << " " << chemistry << " " << biology << " " << total << endl;
            return;
        }
        else {
            cout << id << ": " << chinese << " " << math << " " << english << " " << physics << " " << chemistry << " " << biology << " " << "invalid" << endl;
            return;
        }
    }

};

int main() {

    //cout << "输入学生数量。" << endl;

    int studentNum = 0;
    cin >> studentNum;

    vector<Student> students(studentNum);
    int id;         // 学号
    int chinese;    // 语文
    int math;       // 数学
    int english;    // 英语
    int physics;    // 物理
    int chemistry;  // 化学
    int biology;    // 生物
    for (int i = 0; i < studentNum; i++) {
        cin >> id >> chinese >> math >> english >> physics >> chemistry >> biology;
        students[i] = Student(id, chinese, math, english, physics, chemistry, biology);
    }

    //cout << "输入排序方式（1表示按学号排序，2表示按总分排序）。" << endl;

    int measure = 0;

    cin >> measure;

    if (measure == 1) {
        // 按学号升序排序
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            // 无效成绩的学生排在最后
            if (a.invalid && !b.invalid) return false;
            if (!a.invalid && b.invalid) return true;
            // 都是无效成绩，保持原顺序（稳定排序）
            if (a.invalid && b.invalid) return false;
            // 都是有效成绩，按学号升序
            return a.id < b.id;
            });

        for (const auto& student : students) {
            student.show();
        }
    }
    else if (measure == 2) {
        // 按总分降序排序
        sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            // 无效成绩的学生排在最后
            if (a.invalid && !b.invalid) return false;
            if (!a.invalid && b.invalid) return true;
            // 都是无效成绩，保持原顺序（稳定排序）
            if (a.invalid && b.invalid) return false;
            // 都是有效成绩，按总分降序
            return a.total > b.total;
            });

        for (const auto& student : students) {
            student.show();
        }
    }
    else {
        //cout << "输入方法错误！" << endl;
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
