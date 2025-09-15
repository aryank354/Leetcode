class Solution {
public:
    bool solve(vector<int>&nums , int n , int wt , vector<vector<int>>&t){
       if (wt == 0) return true;
       if (n == 0) return false;
       if(t[n][wt] != -1){
        return t[n][wt];
       }

        if(nums[n-1] <= wt){
            return t[n][wt] = solve(nums , n-1 , wt-nums[n-1], t) || solve(nums , n-1 , wt , t);
        }else{
            return t[n][wt]=solve(nums , n-1 , wt , t);
        }
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0 ; i<n ; i++){
            sum += nums[i];
        }
        if(sum %2 != 0){
            return false;
        }
        vector<vector<int>>t(n+1 , vector<int>((sum/2) + 1 , -1));
        return solve(nums, n , sum/2 , t);
    }
};