class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int, int>> position;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                position[mat[i][j]] = {i, j};
            }
        }

        vector<int> rowPaint(m, 0), colPaint(n, 0);
        
        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            int r = position[num].first;
            int c = position[num].second;
            
            rowPaint[r]++;
            colPaint[c]++;

            if (rowPaint[r] == n || colPaint[c] == m) {
                return i;
            }
        }

        return -1; 
    }
};