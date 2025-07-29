class Solution {
public:


void dfs(int x , int y , vector<vector<char>>&grid , vector<vector<int>>&vis , int n , int m){
    
    vis[x][y] = 1;
    int dx[4] = { -1 , 0 , 1 , 0};
    int dy[4] = {0 , 1 , 0 , -1};

    for(int i =0 ; i<4 ; i++){
        int delx = x + dx[i];
        int dely = y + dy[i];

        if(delx >= 0 && delx <n && dely >= 0 && dely <m && vis[delx][dely] == 0 && grid[delx][dely] == '1'){
            vis[delx][dely] = 1;
            dfs(delx , dely , grid , vis , n , m);
        }
    }
}



int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>vis(n , vector<int>(m,0));
    int count = 0;

    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            if(vis[i][j] == 0 && grid[i][j] == '1'){
                count++;
                dfs(i , j , grid , vis , n , m);
            }
        }
    }

    return count;

    }
};
