/**/
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<double>fi(n);
	for(int i=0; i < n; i++) {
		cin >> fi[i];
	}
	vector<double>pi(n);
	for (int i = 0; i < n; i++) {
		cin >> pi[i];
	}

	double result=0;
	for (int i = 0; i < n; i++) {
		result += fi[i] * pi[i];
	}

	cout << result;



}