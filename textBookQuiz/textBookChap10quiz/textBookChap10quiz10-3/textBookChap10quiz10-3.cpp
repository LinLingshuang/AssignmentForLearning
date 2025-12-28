/*简单说明插入选择的算法思想，初始化数组data[]={1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14,16,18,20}
调用教材中的直接选择排序函数模板进行排序，对此函数模板稍作修改，加入输出语句，在每输出一个待排序元素后显示整个数组，
观测排序过程中数据的变化，加深对选择排序算法的理解*/
#include <iostream>
using namespace std;

int orgin[] = { 1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14,16,18,20 };

template<class T>
void mySwap(T& x, T& y) {
    T temp = x;
    x = y;
    y = temp;
}

template<class T>
void selectionSort(T a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int leastIndex = i;

        for (int j = i+1; j < n; j++) {
            if (a[j] < a[leastIndex]) {
                leastIndex = j;
            }
        }
        mySwap(a[i], a[leastIndex]);
        cout << endl << "orgin:";
        for (int m = 0; m < n; m++) {
            cout.width(3);
            cout << orgin[m];
        }
        cout << endl << " new: ";
        for (int k = 0; k < n; k++) {
            cout.width(3);
            cout << a[k];
        }
    }
    cout << endl << "orgin:";
    for (int m = 0; m < n; m++) {
        cout.width(3);
        cout << orgin[m];
    }
    cout << endl << " new: ";
    for (int k = 0; k < n; k++) {
        cout.width(3);
        cout << a[k];
    }
}

int main()
{
    int data[] = { 1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14,16,18,20 };

    selectionSort(data, 20);
}
