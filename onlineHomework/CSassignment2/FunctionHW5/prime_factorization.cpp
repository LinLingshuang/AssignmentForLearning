#include "prime_factorization.h"

std::vector<int> factorize(int N) {
    std::vector<int> factors;
    
    // 处理2的因子
    while (N % 2 == 0) {
        factors.push_back(2);
        N /= 2;
    }
    
    // 处理其他奇数因子
    for (int i = 3; i * i <= N; i += 2) {
        while (N % i == 0) {
            factors.push_back(i);
            N /= i;
        }
    }
    
    // 如果剩下的数大于2，说明它是一个质数
    if (N > 2) {
        factors.push_back(N);
    }
    
    return factors;
}