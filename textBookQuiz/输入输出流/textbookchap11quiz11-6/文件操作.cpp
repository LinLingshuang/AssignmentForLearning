/*定义一个Dog类，包含体重和年龄两个成员变量及相应的成员函数，声明一个实例dog1，体重为5，年龄为10，使用I/O流把dog1的状态写入磁盘文件，
再声明另一个实例dog2通过读取文件把dog1的状态赋给dog2.分别用文本方式和二进制方式操作文件，看看结果，再看看文件的ASCII码有何不同*/
#include <iostream>
#include<fstream>
using namespace std;

class Dog {
public:
    Dog() {}
    Dog(int w,int a):weigth(w),age(a){}

    void setweigth(int w) { this->weigth = w; }
    void setage(int a) { this->age = a; }

    void showweigth() { cout << this->weigth<<endl; }
    void showage() { cout << this->age<<endl; }

    int weigth;

    int age;


};

int main()
{
    Dog dog1(5, 10);

    ofstream file;

    file.open("dog1.txt");

    file << dog1.weigth << ' ' << dog1.age;

    file.close();

    Dog dog2;

    ifstream input("dog1.txt",ios_base::in|ios_base::in);

    int inputw;

    int inputa;

    input >> inputw >> inputa;

    dog2.setweigth(inputw);

    dog2.setage(inputa);

    dog2.showweigth();

    dog2.showage();

    input.close();
    
    ifstream input1("dog1.txt", ios_base::in | ios_base::binary);

    int inputw1;

    int inputa1;

    input1 >> inputw1 >> inputa1;

    dog2.setweigth(inputw1);

    dog2.setage(inputa1);

    dog2.showweigth();

    dog2.showage();

    input.close();
    
}

