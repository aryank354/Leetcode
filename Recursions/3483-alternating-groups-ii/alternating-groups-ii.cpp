class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        
        vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = (colors[i] != colors[(i + 1) % n]);
        }
        

        vector<int> prefix(2 * n + 1, 0);
        for (int i = 0; i < 2 * n; i++) {
            prefix[i + 1] = prefix[i] + diff[i % n];
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int windowSum = prefix[i + k - 1] - prefix[i];
            if (windowSum == k - 1) {
                ans++;
            }
        }
        
        return ans;
    }
};
