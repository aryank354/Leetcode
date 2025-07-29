class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int time) {
        int n = grid.size();
        int m = grid[0].size();

        // If out of bounds or cell is empty or already has lesser/equal time rot
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0) return;
        if (grid[i][j] > 1 && grid[i][j] < time) return;

        grid[i][j] = time; // Update rot time

        dfs(grid, i + 1, j, time + 1);
        dfs(grid, i - 1, j, time + 1);
        dfs(grid, i, j + 1, time + 1);
        dfs(grid, i, j - 1, time + 1);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Start DFS from all initially rotten oranges
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    dfs(grid, i, j, 2); // Start time from 2 to distinguish from fresh
                }
            }
        }

        int maxTime = 2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) return -1;  // Fresh orange remains
                maxTime = max(maxTime, grid[i][j]);
            }
        }

        return maxTime - 2; // Subtract initial offset
    }
};
