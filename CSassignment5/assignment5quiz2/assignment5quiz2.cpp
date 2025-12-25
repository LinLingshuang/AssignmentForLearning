#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <cstring>



using namespace std;

struct Student

{

	long no;         //Ñ§ºÅ

	char name[20];   //ÐÕÃû

	int age;         //ÄêÁä

};

void fun1(Student s) { //no=1000;name=leoonard;age=29

	s.no = 1000;

	strcpy(s.name, "Leonard");

	s.age = 29;

}

void fun2(Student* p) {

	p->no = 2000;

	strcpy(p->name, "Howard");

	p->age = 27;

}

void main() {

	Student s1 = { 1234,"Sheldon",30 };

	Student s2 = s1;//{ 1234,"Sheldon",30 };

	fun1(s1);

	fun2(&s2);
	//no=1000;name=leoonard;age=29
	cout << s1.no << ", " << s1.name << ", " << s1.age << endl;//1234, Sheldon, 30

	cout << s2.no << ", " << s2.name << ", " << s2.age << endl;//2000, Howard, 27

	return;

}