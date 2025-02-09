class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1; // Base case
        unsigned int m;

        if (n < 0) {
            m = n;
            x = 1 / x;
            m = -m;

        if (m % 2 == 0) {
            return myPow(x * x, m / 2); // Reduce exponent
        } else {
            return x * myPow(x * x, m / 2); // Multiply x for odd exponent
        }    
        }

        if (n % 2 == 0) {
            return myPow(x * x, n / 2); // Reduce exponent
        } else {
            return x * myPow(x * x, n / 2); // Multiply x for odd exponent
        }
    }
};
