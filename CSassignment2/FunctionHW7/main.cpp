#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "student.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    
    // 确保学生人数不超过50
    if (n > 50) {
        n = 50;
    }
    
    vector<Student> students(n);
    
    // 读取学生信息
    for (int i = 0; i < n; ++i) {
        cin >> students[i].id >> students[i].name >> students[i].age;
    }
    
    // 按姓名排序并输出
    vector<Student> studentsByName = students;
    sort(studentsByName.begin(), studentsByName.end(), compareByName);
    
    for (const auto& student : studentsByName) {
        cout << setw(3) << student.id << setw(6) << student.name << setw(3) << student.age << endl;
    }
    
    // 输出空行分隔
    cout << endl;
    
    // 按年龄排序并输出
    vector<Student> studentsByAge = students;
    sort(studentsByAge.begin(), studentsByAge.end(), compareByAge);
    
    for (const auto& student : studentsByAge) {
        cout << setw(3) << student.id << setw(6) << student.name << setw(3) << student.age << endl;
    }
    
    return 0;
}