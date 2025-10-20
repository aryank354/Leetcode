class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int freq = 0;
        int ans = 0;

        for(auto it : nums){
            if(freq == 0){
                ans = it;
            }

            if(it == ans){
                freq++;
            }
            else{
                freq--;
            }

        }

        return ans;
    }
};