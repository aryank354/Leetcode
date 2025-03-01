class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Merge adjacent equal numbers
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        // Step 2: Shift non-zero elements to the left
        int insertPos = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[insertPos++] = nums[i];
            }
        }

        // Step 3: Fill the remaining positions with zeros
        while (insertPos < n) {
            nums[insertPos++] = 0;
        }

        return nums;
    }
};
