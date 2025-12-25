/*3-13、用递归的方法编写函数 求Fiboonacci级数，公式为：
Fn= Fn-1+ Fn-2(n>2), F1= F2=1
注意观察递归调用的过程。*/

#include<iostream>
using namespace std;

int Fiboonacci(int n) {
	if (n == 1 || n == 2)return 1;
	else return Fiboonacci(n - 1) + Fiboonacci(n - 2);
}

int main() {
	int input;
	cin >> input;
	cout << Fiboonacci(input);

}