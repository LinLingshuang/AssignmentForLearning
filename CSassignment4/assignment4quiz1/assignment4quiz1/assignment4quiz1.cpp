#include <iostream>

using namespace std;

void sort(int arr[], int n) {

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n - 1; j++) {

			if (arr[j] > arr[j + 1]) {

				int temp = arr[j];

				arr[j] = arr[j + 1];

				arr[j + 1] = temp;

			}

		}

	}

}

void print(int arr[], int n) {

	for (int i = 0; i < n; i++) {

		cout << arr[i];

	}

}

void main() {

	int a[7] = { 3,5,2,9,6,4,8 };

	sort(a, 7);

	print(a, 7);

	int b[5] = { 33,55,22,99,66 };

	sort(b, 5);

	print(b, 5);

	return;

}