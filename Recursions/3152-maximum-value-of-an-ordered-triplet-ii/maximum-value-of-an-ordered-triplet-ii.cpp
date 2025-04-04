class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
         int n = nums.size();

         vector<int>leftval(n, 0);
         vector<int>rightval(n, 0);

         for(int j = 1; j<n ; j++){
            leftval[j] = max(nums[j-1] , leftval[j-1]);
         }

         for(int j = n-2 ; j>=0 ; j--){
            rightval[j] = max(nums[j+1] , rightval[j+1]);
         }

         long long result  = 0;
         for(int j = 0 ; j<n ; j++){
            result = max(result , (long long)(leftval[j]-nums[j]) * rightval[j]);
         }

         return result;
    }
};