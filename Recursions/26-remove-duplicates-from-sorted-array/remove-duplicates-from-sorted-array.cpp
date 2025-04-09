class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int j = 0 ; j<nums.size() ; j++){
            if(nums[j] != nums[i]){
                nums[++i] = nums[j];
            }
        }

        nums.resize(i+1);

        return nums.size();
        
    }
};