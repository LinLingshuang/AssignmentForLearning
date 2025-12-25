#ifndef PRIME_FACTORIZATION_H
#define PRIME_FACTORIZATION_H

#include <vector>

/**
 * 对正整数N进行质因数分解
 * @param N 需要分解的正整数（2<=N<=65535）
 * @return 质因数的vector，按从小到大排序
 */
std::vector<int> factorize(int N);

#endif // PRIME_FACTORIZATION_H