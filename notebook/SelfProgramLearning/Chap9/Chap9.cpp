//模板
#include<iostream>
using namespace std;

template<class T>
class DemoClass;
typedef DemoClass<int>IntDemoClass;
using DoubleDemoClass = DemoClass<double>;


template<class a,class b>
void fun(a a1, b b1) {
	cout << a << b;
}


template<class T>
class base {


};


int main() {
	int a = 10;
	double b = 10.0;

	fun(a, b);



}