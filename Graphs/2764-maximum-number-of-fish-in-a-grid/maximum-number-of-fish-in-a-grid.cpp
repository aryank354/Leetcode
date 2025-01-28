class Solution {
public:
int findMaxFish(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) return 0;
    
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    queue<pair<int, int>> q;
    int max_fish = 0;
    const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] > 0 && !visited[i][j]) {
                visited[i][j] = true;
                q.push({i, j});
                
                int current = grid[i][j];
                while (!q.empty()) {
                    auto curr = q.front();
                    q.pop();
                    
                    for (int k = 0; k < 4; ++k) {
                        int ni = curr.first + dirs[k][0];
                        int nj = curr.second + dirs[k][1];
                        
                        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols &&
                            !visited[ni][nj] && grid[ni][nj] > 0) {
                            visited[ni][nj] = true;
                            current += grid[ni][nj];
                            q.push({ni, nj});
                        }
                    }
                }
                
                if (current > max_fish) {
                    max_fish = current;
                }
            }
        }
    }
    
    return max_fish;
}
};