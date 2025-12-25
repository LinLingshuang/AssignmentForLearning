#ifndef STUDENT_H
#define STUDENT_H

#include <string>

struct Student {
    int id;
    std::string name;
    int age;
};

// 按姓名排序的比较函数
bool compareByName(const Student& a, const Student& b);

// 按年龄排序的比较函数，年龄相同时按姓名排序
bool compareByAge(const Student& a, const Student& b);

#endif // STUDENT_H