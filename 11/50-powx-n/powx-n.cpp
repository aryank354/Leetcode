// IBH APPROACH

// class Solution {
// public:
//     double myPow(double x, int n) {
//         if(n == 0){
//             return 1;
//         }
//         return myPow(x , n-1) * x;        
//     }
// };

// OPTIMIZED APPROACH O(LogN);
// class Solution {
// public:
//     double myPow(double x, int n) {

//         if(n == 0){
//             return 1;
//         }

//         double half = myPow(x , n/2);
//         if(n %2 == 0){
//             return half * half;
//         }
//         else{
//             return x * half * half;
//         }
        
//     }
// };

// Handling negative case
class Solution {
public:
    double myPow(double &x, int n) {
        long long N = n;
        if(N < 0){
            N = -N;
            x = 1/x;
        }

        if(N == 0){
            return 1;
        }

        double half = myPow(x , N/2);
        if(N %2 == 0){
            return half * half;
        }
        else{
            return x * half * half;
        }
        
    }
};
