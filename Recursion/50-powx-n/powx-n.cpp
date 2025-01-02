// class Solution {
// public:
// binary Exponentiation method
// TC:- O(logn)

//     double myPow(double x, int n) {
//         long long binaryform = n;
//         double ans = 1;

//         // if n is negative

//         if( binaryform < 0){
//             binaryform = -binaryform;
//             x = 1/x;
//         }

//         while(binaryform>0){
//             if(binaryform % 2 == 1){
//                 ans *= x;
//             }
//             x *= x;
//             binaryform /= 2;
//         }


//         return ans;
        
//     }

// };


// method 2 : using recursion
class Solution {
public:
    double powHelper(double x, long long n) {
        // Base case: if n is 0, return 1
        if (n == 0) return 1;

        // Recursive step
        double half = powHelper(x, n / 2); // Divide the exponent by 2
        if (n % 2 == 0) {
            return half * half; // If n is even
        } else {
            return half * half * x; // If n is odd
        }
    }
    double myPow(double x, int n) {
        // Convert n to long long to handle edge cases like INT_MIN
        long long binaryform = n;

        // Handle negative exponents
        if (binaryform < 0) {
            binaryform = -binaryform;
            x = 1 / x;
        }

        // Recursive helper function
        return powHelper(x, binaryform);
    }

};


