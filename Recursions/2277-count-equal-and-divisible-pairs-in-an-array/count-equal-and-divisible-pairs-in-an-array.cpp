class Solution {
public:
    int countPairs(std::vector<int>& nums, int k) {

        int n  =  nums.size();
         
        int ans  = 0;

        unordered_map<int, std::vector<int>> valToIndices;

        for (int i = 0; i < n; ++i) {

            valToIndices[nums[i]].push_back(i);
        }

        for (auto& [val, indices] : valToIndices) {

            map<int, int> gcdCount;
            
            for (int idx : indices) {
                int g = std::gcd(idx, k);
                for (const auto& [g2, cnt] : gcdCount) {
                    if ((1LL * g * g2) % k == 0) {
                        ans += cnt;
                    }
                }
                gcdCount[g]++;
            }
        }
        return ans;
    }
};
