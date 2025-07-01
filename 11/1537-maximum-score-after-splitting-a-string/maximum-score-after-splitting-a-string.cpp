/*
// Brute Force Approach
// TC: O(n^2)
// SC: O(1)
class Solution {
public:
    int func(string s , int m){
        int n = s.size();
        int leftSum = 0;
        int rightSum = 0;

        for(int i = 0 ; i<n ; i++ ){
            if(i <= m  && s[i] == '0' ){
                leftSum++;
            }
            else if(i > m && s[i] == '1'){
                rightSum++;
            }
        }

        return leftSum + rightSum;
    }

    int maxScore(string s) {
        int maxi = 0;
        int n  = s.size();

        for(int i = 0 ; i<n ; i++){
            int ans = func(s , i);
            maxi = max(maxi , ans);
        }
        return maxi;
    }
};
*/

class Solution {
public:
    int maxScore(string s) {

        int maxi = 0;
        int n  = s.size();

        vector<int>left(n,0);
        vector<int>right(n,0);

        // for calc left sum string
        for(int i = 0 ; i<n ; i++){
            if(i == 0 && s[i] == '0'){
                left[i] = left[i] + 1;
                continue;
            }

            if(s[i] == '0' && i>0 ){
                left[i]++;
            }

            if(i > 0){
            left[i] += left[i-1];
            }
        }

        // for calc rigt sum calc
        for(int i = n-1 ; i >= 0 ; i--){

            if(i == n-1 && s[i] == '1'){
                right[i] = right[i] + 1;
                continue;
            }

            if(s[i] == '1' && i<n-1 ){
                right[i]++;
            }

            if(i< n-1){
            right[i] += right[i+1];

            }
        }

        for(int i = 0 ; i<n-1 ; i++){
            maxi = max(maxi , left[i] + right[i+1] );
        }

        
        return maxi;
    }
};

