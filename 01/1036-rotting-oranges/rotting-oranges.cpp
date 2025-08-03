// class Solution {
// public:

// int dx[4] = {-1, 0, 1, 0};
// int dy[4] = {0, 1, 0, -1};

// void dfs(int x, int y, int t , vector<vector<int>>&grid , vector<vector<int>>&time , int n ,int m) {
//         if (x < 0 || x >= n || y < 0 || y >= m) return;
//         if (grid[x][y] == 0 || time[x][y] <= t) return;

//         time[x][y] = t;

//         for (int i = 0; i < 4; i++) {
//             dfs(x + dx[i], y + dy[i], t + 1 , grid , time , n , m);
//         }
//     };

    
// int orangesRotting(vector<vector<int>>& grid) {
//     int n = grid.size();
//     int m = grid[0].size();

//     vector<vector<int>> time(n, vector<int>(m, INT_MAX));



//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (grid[i][j] == 2) {
//                 dfs(i, j, 0 , grid , time , n , m);
//             }
//         }
//     }

//     int maxTime = 0;

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (grid[i][j] == 1) {
//                 if (time[i][j] == INT_MAX) return -1; 
//                 maxTime = max(maxTime, time[i][j]);
//             }
//         }
//     }

//     return maxTime;
// }

// };

class Solution {
public:




    
int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>vis(n , vector<int>(m , 0));

    queue<pair<pair<int, int> , int>>q;
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            if(grid[i][j] == 2){
                q.push({{i , j} , 0});
                vis[i][j] = 1;
            }
        }
    }
    int time = 0;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int t = q.front().second;
        q.pop();
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        time = max(time , t);

        for(int i = 0 ; i<4 ; i++){
        int newx = x + dx[i];
        int newy = y + dy[i];

        if(newx >=0 && newx <n && newy >= 0 && newy < m && grid[newx][newy] == 1 && vis[newx][newy] == 0){
            q.push({{newx , newy} , t+1});
            vis[newx][newy] = 1;
        }
        }


    }


        for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(grid[i][j] == 1 && vis[i][j] == 0) {
                return -1;  // ❌ Some oranges were never rotted
            }
        }
    }


    return time;
}

};

