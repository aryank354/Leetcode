class Solution {
public:
// binary Exponentiation method
// TC:- O(logn)

    double myPow(double x, int n) {
        long long binaryform = n;
        double ans = 1;

        // if n is negative

        if( n < 0){
            binaryform = -binaryform;
            x = 1/x;
        }

        while(binaryform>0){
            if(binaryform % 2 == 1){
                ans *= x;
            }
            x *= x;
            binaryform /= 2;
        }


        return ans;
        
    }

};