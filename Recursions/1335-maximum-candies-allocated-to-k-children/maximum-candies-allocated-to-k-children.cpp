class Solution {
public:
    bool canAllocate(vector<int>& candies, long long k, int mid) {
        long long count = 0;
        for (int c : candies) {
            count += c / mid;  // How many children can get "mid" candies from this pile?
        }
        return count >= k;  // We need at least "k" children to be satisfied
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        if (accumulate(candies.begin(), candies.end(), 0LL) < k) return 0; // Not enough candies
        
        int left = 1, right = *max_element(candies.begin(), candies.end());
        int ans = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAllocate(candies, k, mid)) {
                ans = mid;  // Try a higher value
                left = mid + 1;
            } else {
                right = mid - 1;  // Reduce the value
            }
        }
        return ans;
    }
};
