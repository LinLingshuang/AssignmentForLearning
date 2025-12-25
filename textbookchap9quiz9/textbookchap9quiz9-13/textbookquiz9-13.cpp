/*9-13简单说明交换排序的算法思想。*/
// 交换排序的基本思想是通过比较和交换数组中的元素位置来实现排序。具体步骤如下：
// 1. 从数组的第一个元素开始，依次比较相邻的两个元素。
// 2. 如果前一个元素大于后一个元素，则交换它们的位置。
// 3. 重复步骤1和2，直到数组的末尾，这样最大的元素就会被交换到数组的最后位置。
// 4. 然后对剩下的元素重复上述过程，直到整个数组有序为止。
// 交换排序的时间复杂度为O(n^2)，适用于小规模数据的排序。
//
#include <iostream>
using namespace std;

int main() {
	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				// 交换 arr[j] 和 arr[j+1]
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	cout << "Sorted array: \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;

}
