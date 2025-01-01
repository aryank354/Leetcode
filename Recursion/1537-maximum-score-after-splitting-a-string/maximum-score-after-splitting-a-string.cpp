class Solution {
public:
    int maxScore(string s) {

        int maxi = 0;
        int n = s.size();
        int zeroCount = 0;
        int oneCount = 0;

        for(int i = 0 ; i<n ; i++){
            if(s[i] == '1')
            oneCount++;
        }

        for(int i = 0 ; i<n-1 ; i++){
            int val = s[i] - '0';
            if(val == 0){
                zeroCount++;
            }
            else if(val == 1){
                oneCount--;
            }

            maxi = max(maxi , (zeroCount + oneCount));

        }

        return maxi;
        
    }
};