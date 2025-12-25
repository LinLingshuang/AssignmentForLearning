/*简单说明插入排序的算法思想。*/

/*答：将数组分为已排序区间和未排序区间，
未排区间取数后在已排区间里从左往右或从右往左进行比较并插入，
可以减少重复比较与插入，不用每次排序遍历所有元素*/
#include <iostream>
using namespace std;

int main() {
	int arr[] = { 12, 11, 13, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int j = i - 1;
		// 将 key 插入到已排序区间 arr[0..i-1]
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
	cout << "Sorted array: \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}