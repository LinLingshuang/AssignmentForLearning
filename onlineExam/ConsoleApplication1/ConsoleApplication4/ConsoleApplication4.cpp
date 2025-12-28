/*3. 动态数组类实现深复制
【问题描述】
请补充完整下面空白的程序语句。
本题要完成一个动态整型数组类 DynamicArray 的定义，它要支持构造函数、深复制构造函数、赋值运算符重载、析构函数以及基本的set和print方法。
动态数组的元素个数不超过50，元素类型为int，数组元素数据存储在动态创建的int型数组中，数组元素值初始化为0。
构造函数接收一个整数参数，表示数组的大小。
深复制构造函数接收一个 DynamicArray 对象的引用，实现深复制。
赋值运算符重载实现深复制。
析构函数释放动态数组所占用的内存。
set方法接收两个整数参数，表示要设置的数组元素的索引和值。
print方法输出数组的所有元素值。
【输入形式】
从键盘输入数组的大小和元素值。
【输出形式】
输出数组1和数组2的所有元素值。
【样例输入】
3
10 20 30
【样例输出】
Array 1:10 20 30
Array 2 : 10 20 30
【样例说明】
输入数组大小为3，元素值分别为10、20、30。输出数组1和数组2的元素值都为10、20、30。
*/
#include <iostream>
using namespace std;

class DynamicArray
{
private:
    int* data; // 动态数组数据元素指针
    int size;  // 动态数组大小

public:
    DynamicArray(int s)
    {
        size = s;
        data = new int[s];
        for (int i = 0; i < s; ++i)
            data[i] = 0;
    }

    DynamicArray(const DynamicArray& other)
    {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; ++i)

            data[i] = other.data[i];// 空1
    }

    DynamicArray& operator=(const DynamicArray& other)
    {
        if (this == &other)
            return *this;

        delete[] data;
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; ++i)

            data[i] = other.data[i];// 空2

        return *this; // 空3
    }

    ~DynamicArray()
    {

        delete[] data;// 空4
    }

    void set(int index, int val)
    {
        if (index >= 0 && index < size)

            data[index] = val;// 空5
    }

    void print() const
    {
        for (int i = 0; i < size; ++i)
            cout << data[i] << " ";
        cout << endl;
    }
};

int main()
{
    int arrSize = 0;
    int arrValue = 0;

    cin >> arrSize;
    if (arrSize < 0 || arrSize > 50)
    {
        cout << "Invalid size" << endl;
        return 1;
    }

    DynamicArray arr1(arrSize);
    for (int i = 0; i < arrSize; i++)
    {
        cin >> arrValue;
        arr1.set(i, arrValue);
    }
    cout << "Array 1:";
    arr1.print();

    DynamicArray arr2 = arr1;
    cout << "Array 2:";
    arr2.print();

    return 0;
}
