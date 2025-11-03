// class Solution {
// public:
//     int minCost(string colors, vector<int>& neededTime) {
//         int prev = 0;
//         int curr = 0;
//         int time = 0;
//         int n = colors.length();

//         for(int i = 0 ; i<n ; i++){
//             curr = neededTime[i];
//             time += min(prev , curr);
//             prev = max(prev , curr);
//         }

//         return time;
//     }
// };



class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int prev = 0;
        int curr = 0;
        int time = 0;
        int n = colors.length();

        for(int i = 0 ; i<n ; i++){


            if( i>0 && (colors[i-1] != colors[i]) ){
                prev = 0;
            }
            curr = neededTime[i];
            time += min(prev , curr);
            prev = max(prev , curr);


        }

        return time;
    }
};