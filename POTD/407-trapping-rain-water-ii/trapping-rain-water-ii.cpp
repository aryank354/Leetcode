#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        
        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        
        // Step 1: Push all boundary cells into the minHeap
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    minHeap.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }
        
        // Directions for moving (up, down, left, right)
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        int waterTrapped = 0;
        
        // Step 2: Process cells in priority queue
        while (!minHeap.empty()) {
            auto [height, cell] = minHeap.top();
            minHeap.pop();
            
            int x = cell.first, y = cell.second;
            
            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    
                    // If the current cell is lower, water is trapped
                    waterTrapped += max(0, height - heightMap[nx][ny]);
                    
                    // Push the updated height into the heap
                    minHeap.push({max(heightMap[nx][ny], height), {nx, ny}});
                }
            }
        }
        
        return waterTrapped;
    }
};
