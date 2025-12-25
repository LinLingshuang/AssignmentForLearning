/*使用I/O流以文本方式建立一个文件test1.txt，写入字符“已成功写入文件！”*/
#include<iostream>
#include<fstream>
using namespace std;

int main() {
	ofstream file;

	file.open("test1.txt");

	file << "已成功写入文件！";

	file.close();



}