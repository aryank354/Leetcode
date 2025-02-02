class Solution {
public:
    bool check(vector<int>& nums) {

        ios::sync_with_stdio(false);
        int n = nums.size();
        int count  = 0;
        for(int i = 0 ; i<n-1 ; i++){
            if(nums[i] > nums[i+1]){
                count++;
            }
        }

        if(nums[n - 1] > nums[0]){
            count++;
        }
        
        
    if(count == 1 || count == 0) return true;
    return false;

    }
};