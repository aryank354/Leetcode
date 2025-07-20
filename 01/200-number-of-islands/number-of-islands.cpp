class Solution {
public:
    void bfs(int x, int y, vector<vector<int>> &vis, vector<vector<char>>& grid, int &count) {
        count++;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({x, y});
        vis[x][y] = 1;

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            int nodex = q.front().first;
            int nodey = q.front().second;
            q.pop();

            for (int k = 0; k < 4; ++k) {
                int delx = nodex + dx[k];
                int dely = nodey + dy[k];

                if (delx >= 0 && delx < n && dely >= 0 && dely < m &&
                    grid[delx][dely] == '1' && vis[delx][dely] == 0) {
                    q.push({delx, dely});
                    vis[delx][dely] = 1;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && grid[i][j] == '1') {
                    bfs(i, j, vis, grid, count);
                }
            }
        }

        return count;
    }
};
