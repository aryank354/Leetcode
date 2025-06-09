class Solution {
public:
    int findKthNumber(int n, int k) {
        long long current_num = 1;
        k--;

        while (k > 0) {
            long long steps = 0;
            long long n1 = current_num;
            long long n2 = current_num + 1;
            while (n1 <= n) {
                steps += std::min((long long)n + 1, n2) - n1;
                n1 *= 10;
                n2 *= 10;
            }

            if (steps <= k) {
                k -= steps;
                current_num++;
            } else {
                k--;
                current_num *= 10;
            }
        }
        
        return (int)current_num;
    }
};