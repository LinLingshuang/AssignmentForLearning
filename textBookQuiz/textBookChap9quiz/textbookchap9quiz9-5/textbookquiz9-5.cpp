/*使用本章节的链表类模板，声明两个int类型的链表a，b，分别插入5个元素，然后把b中的元素加到a的尾部*/
#include <iostream>
#include "dlinkedlist.h"
using namespace std;
int main() {
	DLinkedList<int> a, b;
	for (int i = 1; i <= 5; i++) {
		a.insertLast(i);
		b.insertLast(i + 5);
	}
	b.moveToStart();
	for (int i = 1; i <= 5; i++) {
		a.moveToEnd();
		int val;
		b.getCurrentData(val);
		a.insertAfterCurrent(val);
		b.next();
		
	}
	a.moveToStart();
	for (int i = 0; i < a.getSize(); i++) {
		int val;
		a.getCurrentData(val);
		cout << val << " ";
		a.next();
	}



}