/*编写程序提示用户输入一个班级中的学生人数n，
在依次提示用户输入n个学生在课程A中的考试成绩，然后计算出平均成绩，显示出来，
请用教材第九章的数组类模板Array定义浮点数组存储考试成绩*/

#include<iostream>
using namespace std;

template<class T>
class Array {
public:
	Array(int size):size(size){
		T* arr1 = new T[size];
		arr = arr1;
		data = 0;
	}
	void input() {
		for (int i = 0; i < size; i++) {
			cout << "请输入第" << i + 1 << "个学生的成绩：";
			cin >> arr[i];
			data += arr[i];
		}
	}
	T average() {
		return static_cast<T>(data) / size;
	}

private:
	T* arr;
	int data;
	int size;
};

int main() {
	int n;
	
	cout << "请输入班级中学生的人数：";
	cin >> n;
	Array<float>score(n);
	score.input();
	cout << "平均成绩为：" << score.average() << endl;


}