/*对类Point重载“++”自增、“--”自减运算符，要求同时重载前后缀的形式*/

#include<iostream>
using namespace std;

class Point {
public:
	Point(int a = 0,int b=0):x(a),y(b){}

	Point &operator++() {
		++x;
		++y;
		return *this;
	}
	Point operator++(int) {
		Point temp = *this;
		++(*this);
		return temp;
	}
	Point& operator--() {
		--x;
		--y;
		return *this;
	}
	Point operator--(int) {
		Point temp = *this;
		--(*this);
		return temp;
	}

	int getx() { return x; }
	int gety() { return y; }

	friend ostream& operator<<(ostream& os,Point& p) {
		os << "(" << p.getx() << "," << p.gety() << ")" << endl;
		return os;
	}

private:
	int x;
	int y;

};



int main() {
	Point p1(0, 0);
	Point p2(0, 0);
	Point p3(4, 4);
	Point p4(4, 4);

	p1++;
	p2--;
	++p3;
	--p4;

	cout << p1 << p2 << p3 << p4;

}