#include <iostream>
#include <fstream>
#include "MyString.h"

using namespace std;

//要求：对arr数组中的所有对象排序
//排序过程中需要对两个对象比较、交换
//使用MyString的compareTo()和exchangeWith()
// Requirement: Sort all objects in the arr array.
// During the sorting process, two objects need to be compared and exchanged.
// Use MyString's compareTo() and exchangeWith() methods.
void sortMyString(MyString arr[], int count)
{
	//todo 请填写程序
	// Please implement the program.
	//靠前为-1；靠后为1；相等为0
	//exchangeWith(MyString &otherString)
	//compareTo(MyString &otherString)
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count - 1; j++) {
			if (arr[j].compareTo(arr[j + 1]) > 0) {
				arr[j].exchangeWith(arr[j + 1]);
			}
		}

	}
}

int main()
{
	// 请确保names.txt文件与编译后的exe文件位于同一文件夹
	// Please ensure that the names.txt file is in the same folder as the compiled exe file.
	ifstream txtFile("names.txt");
	char txtLine[MyString::CAPACITY];
	//虽然数组定义了150个元素，但文件中只有128个名字，
	//所以只有前128个元素填充了内容并参与排序
	// Although the array is defined with 150 elements, there are only 128 names in the file.
	// Therefore, only the first 128 elements are filled with content and participate in the sorting.
	MyString myArr[150];
	int count = 0;
	//循环读取文件中的每一行，每读一行，填充txtLine数组，
	//再用txtLine数组的内容填充myArr的一个对象，
	//读到文件末尾，getline会返回0，导致循环结束
	// Loop through each line of the file. For each line read, fill the txtLine array,
	// and then use the content of the txtLine array to fill one object in myArr.
	// When the end of the file is reached, getline will return 0, causing the loop to end.
	while (txtFile.getline(txtLine, MyString::CAPACITY))
		myArr[count++].setString(txtLine);
	txtFile.close();
	sortMyString(myArr, count);
	for (int i = 0; i < count; i++)
		cout << myArr[i].getString() << endl;
	return 0;
}
