/*请编写一个哺乳动物类Mammal，在对其派生出狗类Dog，两者都声明speak()成员函数，
该函数在基类里被声明为虚函数，声明一个Dog类对象，通过此对象调用speak()，查看结果*/

#include<iostream>
using namespace std;

class Mammal {
public:

	virtual void speak() {
		cout << "Mammal speaks" << endl;
	}

private:

};

class Dog :public Mammal {
public:
	void speak() {
		cout << "Dog speaks" << endl;
	}

private:

};

int main() {
	Mammal mammal;;

	mammal.speak();

	Dog dog;
	
	dog.speak();
}