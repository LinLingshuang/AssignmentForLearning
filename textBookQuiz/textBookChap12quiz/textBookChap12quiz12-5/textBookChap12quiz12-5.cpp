/*12-5练习使用try、catch语句，在程序中用new分配内时，如果操作未成功，则使用try语句触发一个char类型异常，用catch语句捕获这个异常*/
#include <iostream>

int main()
{
    try {
        int* input = new int[10];

        if (input != NULL) {
            delete[]input;
            throw 'e';
        }

        std::cout << "OK";

    }
    catch (char  c) {

        std::cout << c;

    }


}
