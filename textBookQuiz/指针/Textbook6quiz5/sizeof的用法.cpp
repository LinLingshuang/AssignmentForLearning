/*6-4 已知有一个数组名叫oneArray，用一条语句求出其元素的个数*/
#include<iostream>
using namespace std;

int main() {
	char oneArray[126];

	cout << sizeof(oneArray) / sizeof(oneArray[0]);

}