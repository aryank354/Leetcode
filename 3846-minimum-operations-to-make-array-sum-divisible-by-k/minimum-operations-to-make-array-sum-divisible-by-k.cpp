class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(auto i: nums){
            sum += i;
        }

        return sum % k;
    }
};