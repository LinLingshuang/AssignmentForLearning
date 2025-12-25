/*#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Point {
private:
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    
    // 前缀++
    Point& operator++() {
        ++x;
        ++y;
        return *this;
    }
    
    // 后缀++
    Point operator++(int) {
        Point temp = *this;
        ++(*this);
        return temp;
    }
    
    // 前缀--

    
    // 后缀--

    
    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << "," << p.y << ")";
        return os;
    }
};

int main() {
    int x, y;
    int z=0;
    cin >> x >> y;
    Point p(x, y);
    
    string operations;
    cin.ignore();
    getline(cin, operations);
    
    istringstream iss(operations);
    string op;
    while (iss >> op) {
        z+=1;
        if (op == "++") {
            ++p;
        } 

        else if (op == "---") {
            p--;
        }
        cout << p << endl;
    }
    
    if(z==0){cout << p << endl;}
    
    return 0;
}







*/