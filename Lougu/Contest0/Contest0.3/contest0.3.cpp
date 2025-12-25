/**/
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int t;
	cin >> t;
	vector<int>result(t);
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector<int>m(n);
		for (int j = 0; j < n; j++) {
			cin >> m[j];
		}
		int start = m[0];
		int end = m[n - 1];
		result[i] = start - end;
		int temp = result[i];
		for (int j = 0; j < n - 1; j++) {
			if (m[j] - end > result[i]) {
				result[i] = m[j] - end;
			}
			if (start - m[j + 1] > temp) {
				temp = start - m[j + 1];
			}

		}
		if (end - start > result[i]) {
			result[i] = end - start;
		}
		if (temp > result[i]) {
			result[i] = temp;
		}

	}
	for (int i = 0; i < t; i++) {
		cout << result[i] << endl;
	}
}