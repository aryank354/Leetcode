#include <vector>
#include <unordered_map>

class Solution {
public:
    long long countBadPairs(std::vector<int>& nums) {
        long long n = nums.size();
        long long totalPairs = (n * (n - 1)) / 2;
        std::unordered_map<int, long long> freqMap;
        long long goodPairs = 0;

        for (int i = 0; i < n; i++) {
            int diff = nums[i] - i;
            if (freqMap.find(diff) != freqMap.end()) {
                goodPairs += freqMap[diff];
            }
            freqMap[diff]++;
        }

        return totalPairs - goodPairs;
    }
};
