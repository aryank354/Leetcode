class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // This will store the minimum time at which each cell gets rotten
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));

        // Direction vectors: up, right, down, left
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        // DFS function
        function<void(int, int, int)> dfs = [&](int x, int y, int t) {
            if (x < 0 || x >= n || y < 0 || y >= m) return;
            if (grid[x][y] == 0 || time[x][y] <= t) return;  // wall or already better time

            time[x][y] = t;

            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                dfs(newX, newY, t + 1);
            }
        };

        // Run DFS from each rotten orange (value == 2)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    dfs(i, j, 0);
                }
            }
        }

        int maxTime = 0;

        // Now, check each fresh orange
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    if (time[i][j] == INT_MAX) return -1; // never rotted
                    maxTime = max(maxTime, time[i][j]);
                }
            }
        }

        return maxTime;
    }
};
