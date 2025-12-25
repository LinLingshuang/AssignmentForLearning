#include "student.h"

// 按姓名排序的比较函数
bool compareByName(const Student& a, const Student& b) {
    return a.name < b.name;
}

// 按年龄排序的比较函数，年龄相同时按姓名排序
bool compareByAge(const Student& a, const Student& b) {
    if (a.age != b.age) {
        return a.age < b.age;
    }
    return a.name < b.name;
}