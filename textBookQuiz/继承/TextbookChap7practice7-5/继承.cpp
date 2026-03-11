/*定义一个哺乳类Mammal。由此派生出狗类Dog，定义一个Dog类对象，观察基类与派生类的构造函数与析构函数的调用顺序*/

#include<iostream>
using namespace std;

class Mammal {
public:
	Mammal() :alive(true), legs(4) {
		cout << "construting defult Mammal..." << endl;
	}

	Mammal(bool alive , int legs ) :alive(alive), legs(legs) {

		cout << "construting a Mammal..." << endl;
	}

	~Mammal() {
		cout << "deleting Mammal..." << endl;
	}


private:
	bool alive;
	int legs;


};

class Dog :public Mammal {
public:
	Dog(){
		cout << "construting defult Dog..." << endl;
	}
	Dog(int alive,int legs, bool isdog):Mammal(alive,legs),isdog(isdog) {
		cout << "construting a Dog..." << endl;
	}


	~Dog() {
		cout << "delete Dog..." << endl;
	}
private:
	
	bool isdog;
};

int main() {
	Mammal animal1;
	Mammal animal2(false, 100);
	Dog dog1;
	Dog dog2(false, 4, true);


}