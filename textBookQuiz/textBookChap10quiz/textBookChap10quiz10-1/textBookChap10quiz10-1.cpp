/*简单说明插入排序的算法思想，初始化数组data[]={1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14,16,18,20}
调用教材中的直接插入排序函数模板进行排序，对此函数模板稍作修改，加入输出语句，在每输出一个待排序元素后显示整个数组，
观测排序过程中数据的变化，加深对插入排序算法的理解*/
#include <iostream>
using namespace std;

int orgin[] = { 1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14,16,18,20 };

template<class T>
void insertionSort(T a[], int n) {
    int i, j;
    T temp;
    for (int i = 1; i < n; i++) {
        int j = i;
        T temp = a[i];
        while (j > 0 && temp < a[j - 1]) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = temp;

        cout << endl << "orgin:";
        for (int m = 0; m < n; m++) {
            cout.width(3);
            cout << orgin[m];
        }
        cout << endl << " new: ";
        for (int k = 0; k < i; k++) {
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
    
    insertionSort(data, 20);
}
