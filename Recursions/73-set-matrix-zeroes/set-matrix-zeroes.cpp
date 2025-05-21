class Solution {
public:
    void setZeroes(vector<vector<int>>& vec) {
        int col = vec[0].size();
        int row = vec.size();
        vector<int>vecrow;
        vector<int>veccol;

        for(int i = 0 ; i<row ; i++){
            for(int j = 0 ; j<col; j++){
                if(vec[i][j] == 0){
                    vecrow.push_back(i);
                    veccol.push_back(j);
                }
            }
        }

        for(int i = 0 ; i<vecrow.size() ; i++){
            for(int j = 0 ; j<col ; j++ ){
                vec[vecrow[i]][j] = 0;
            }
        }

        for(int i = 0 ; i<veccol.size() ; i++){
            for(int j = 0 ; j<row ; j++){
                vec[j][veccol[i]] = 0;

            }
        }
    }
};