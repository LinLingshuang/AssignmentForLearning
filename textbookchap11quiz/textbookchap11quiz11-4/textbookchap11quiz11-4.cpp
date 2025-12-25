/*使用I/O流以文本方式打开文件test1.txt，读出其内容并显示*/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main() {
	ifstream file;

	string input;

	file.open("test1.txt");

	getline(file, input);

	cout << input;


}