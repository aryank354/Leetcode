class Solution {
public:



int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    vector<vector<int>>vis(n , vector<int>(m,0));
    queue<pair<int,int>>que;

    int dx[4] = { -1 , 0 , 1 , 0};
    int dy[4] = { 0 , 1, 0 , -1};

    for(int i =0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            if(vis[i][j] == 0 && grid[i][j] == '1'){
                count++;
                que.push({i,j});
                vis[i][j] = 1;

                while(!que.empty()){
                    int x = que.front().first;
                    int y = que.front().second;
                    que.pop();

                    

                    for(int i = 0 ; i<4 ; i++){
                        int newx = x + dx[i];
                        int newy = y + dy[i];

                        if(newx >= 0 && newx <n && newy >=0 && newy < m && vis[newx][newy] == 0 && grid[newx][newy] == '1'){
                            vis[newx][newy] = 1;
                            que.push({newx , newy});
                        }

                    }
                }
            }
        }
    }

    return count;

    }
};
