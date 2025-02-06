class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productCount;
    int n = nums.size();
    int count = 0;

    // Store the count of each product in the map
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int product = nums[i] * nums[j];
            productCount[product]++;
        }
    }

    // For each product found, count the valid tuples
    for (auto& [product, freq] : productCount) {
        if (freq > 1) {
            count += (freq * (freq - 1)) / 2 * 8; // Combination formula: (freq choose 2) * 8
        }
    }

    return count;
        
    }
};