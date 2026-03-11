/*编写一个程序实现如下功能：打开指定的一个文本文件，在每一行前加行号后将其输出到另一个文本文件中*/
#include <iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    cout << "请输入指定的文件名：";
    string filename;
    cin >> filename;

    ifstream infile;
    ofstream outfile;

    infile.open(filename);

    outfile.open("newfile.txt");
    int num = 1;
    while (1) {
        string input;
        getline(infile, input);
        outfile << num << " " << input << endl;
        num++;
        if (input == "0") {
            break;
        }
    }
    outfile.close();

    infile.close();

}
