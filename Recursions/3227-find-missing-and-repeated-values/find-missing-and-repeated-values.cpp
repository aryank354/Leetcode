class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n * n;

        vector<int> freq(total + 1, 0); 
        int repeated = -1, missing = -1;

        for (auto& row : grid) {
            for (int num : row) {
                freq[num]++;
            }
        }

        for (int i = 1; i <= total; i++) {
            if (freq[i] == 2) repeated = i;
            if (freq[i] == 0) missing = i;
        }

        return {repeated, missing};
    }
};
