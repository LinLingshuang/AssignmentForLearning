#include <iostream>
using namespace std;
class Swap

{
public:
    void run(int* x, int& y)
    {
        int k;
        k = (*x);
        (*x) = y;
        y = k;
    }
};

void main()
{
    int a = 8, b = 68;
    cout << "a=" << a << ", b=" << b << endl;
    Swap sw;
    sw.run(&a, b);
    cout << "a=" << a << ", b=" << b << endl;

}