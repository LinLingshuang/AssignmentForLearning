#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	int* intptr;
	char* charptr;
	string* stringptr;
	vector<int*>vectorintptr;

	int a = 1;
	int b = 8;
	
	intptr = &b;
	cout << *intptr << endl;
	*intptr = a;
	cout << *intptr << endl;

	int intarr[5];
	char chararr[5];
	string stringarr[5];
	vector<int[1]>vectorarrint;


	int* intarrptr[10];
	char* chararrptr[10];
	string* stringarrptr[10];





	int* p1[3];//=**
	int (*p2)[3];
	int* p3(int);
	int (*p4)(int);
	int* (*p5)(int);
	int (*p6[3])(int);
	int* (*p7[3])(int);



	struct student{
		long no;
		string name;
		int age;

	};
	student w;
	student* p = new student;
	w.age = 22;
	cout << w.age << endl;
	cout << w.no << endl;

	
	p->no = 10086;
	
	cout << w.no << endl;
	student m;
	cout << m.no << endl;
	cout << p->no << endl;
    
	/*
	* int j = 0;
	for (int i = 0; i < 100; i++) {
		for (int i = 0; i < 100; i++) {
			for (int i = 0; i < 100; i++) {
				for (int i = 0; i < 100; i++) {
					cout << i ;
					j++;
					if (j == 1000) {
						return 0;
					}
				}
			}
		}
	}
	*/


/*

	int* Nullptr = NULL;
	int a;
	int* weirdptr=&a;

	cout << Nullptr<<endl;
	//cout << *Nullptr << endl;
	cout << &Nullptr << endl;
	cout << weirdptr << endl;
	cout << *weirdptr << endl;
	cout << &weirdptr << endl;
	cout << weirdptr+ *weirdptr << endl;
	cout << weirdptr- weirdptr << endl;
	//cout << *(weirdptr + *weirdptr) << endl;
	cout << &*weirdptr<< endl;

	cout << &*&*&*&*&*&*&*&*&*weirdptr << endl;

	int test[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* ptr1=test;
	int** ptr2 = &ptr1;
	int*** ptr3 = &ptr2;
	int** ptr4 = *ptr3;
	int* ptr5 = ptr1 + 1;
	int* ptr6 = ptr1 - 1;

	cout << ptr1 << endl;
	cout << *ptr1 << endl;
	cout << *ptr5 << endl;
	cout << *ptr6 << endl;
	cout << &ptr1 << endl;
	cout << ptr2 << endl;
	cout << *ptr2 << endl;
	cout << **ptr2 << endl;
	cout << &ptr2 << endl;
	cout << ptr3 << endl;
	cout << *ptr3 << endl;
	cout << **ptr3 << endl;
	cout << ***ptr3 << endl;
	cout << &ptr3 << endl;
	cout << ptr4 << endl;
	cout << *ptr4 << endl;
	cout << **ptr4 << endl;
	cout << &ptr4 << endl;

	

	int*******************
	   *******************
	   *******************
	   *******************
	   *******************superptr;

	*/
}