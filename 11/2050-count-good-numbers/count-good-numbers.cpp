// base case hypothesis induction approach
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
//     const int MOD = 1e9 + 7;

// public:
//     int countGoodNumbers(long long n) {
//         if (n == 1) {
//             return 5;
//         }

//         if (n % 2 == 0) {
//             return (1LL * 4 * countGoodNumbers(n - 1)) % MOD;
//         } else {
//             return (1LL * 5 * countGoodNumbers(n - 1)) % MOD;
//         }
//     }
// };

// binary exponentiation approach

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        if (exp == 0) return 1;

        long long half = modPow(base, exp / 2);
        long long result = (half * half) % MOD;

        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }

        return result;
    }

public:
    int countGoodNumbers(long long n) {
        // In your style, n = total digits, start from 1-based logic
        long long evenPos = n / 2;           // positions like 2, 4, 6...
        long long oddPos = (n + 1) / 2;       // positions like 1, 3, 5...

        // Odd positions get 5 choices, even positions get 4
        return (modPow(5, oddPos) * modPow(4, evenPos)) % MOD;
    }
};

