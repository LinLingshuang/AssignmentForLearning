#include <iostream>
#include "prime_factorization.h"
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> factors = factorize(N);
    
    // 输出结果
    if (!factors.empty()) {
        cout << factors[0];
        for (size_t i = 1; i < factors.size(); ++i) {
            cout << " " << factors[i];
        }
    }
    cout << endl;
    
    return 0;
}