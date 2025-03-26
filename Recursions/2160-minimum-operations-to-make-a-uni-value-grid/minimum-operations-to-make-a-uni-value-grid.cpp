class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n  = grid.size();
        int m  = grid[0].size();
        vector<int>values;
        int first_mod = (grid[0][0] % x);


        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j] % x != first_mod ){
                    return -1;
                }
            }
        }    

            for(int i = 0 ; i<n ; i++){
                for(int j = 0 ; j<m ; j++){
                    int m_a = ((grid[i][j] -first_mod) / x);
                    values.push_back(m_a);
                }
            } 

            sort(values.begin() , values.end());
            int median = values[values.size()/2];

            int op = 0;
            for(int i = 0 ; i<values.size() ; i++){
                op += abs(values[i] - median);
            }

            return op;

            

        
        
    }
};