class Solution {
public:
    void solve(vector<int>op , vector<int>nums , vector<vector<int>>&ans){
        if(nums.size() == 0){
            ans.push_back(op);
            return;
        }
        vector<int>op1 = op;
        vector<int>op2 = op;

        op2.push_back(nums[0]);
        nums.erase(nums.begin() + 0);

        solve(op1 , nums , ans);
        solve(op2 , nums , ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>op;
        vector<vector<int>>ans;
        solve(op , nums , ans);

        return ans;
    }
};