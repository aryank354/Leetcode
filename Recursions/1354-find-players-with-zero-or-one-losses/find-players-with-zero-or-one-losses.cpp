class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int , int> looser;

        for(int i =0  ; i<matches.size() ; i++){
            looser[matches[i][1]]++;
        }

        vector<int>notLost;
        vector<int>lostOnce;

        for(int i = 0; i<matches.size() ; i++){
            int looserr = matches[i][1];
            int winner = matches[i][0];

            if(looser.find(winner) == looser.end()){
                notLost.push_back(winner);
                looser[winner] =2;
            }
            if(looser[looserr] == 1){
                lostOnce.push_back(looserr);
                looser[looserr] = 2;
            }
        }

        sort(notLost.begin() , notLost.end());
        sort(lostOnce.begin() , lostOnce.end());


        return {notLost,lostOnce};



        
    }
};