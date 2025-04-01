class Solution {
public:
    
    long long solve(vector<vector<int>>& questions, int idx, vector<long long>&dp){
        if(idx >= questions.size()) return 0;

        if(dp[idx] != -1) return dp[idx];

        long long notTake = solve(questions, idx + 1, dp);
        long long take = questions[idx][0] + solve(questions, idx + questions[idx][1] + 1, dp);

        return dp[idx] = max(take, notTake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        long long result = INT_MIN;
        vector<long long>dp(questions.size(), -1);

        for(int i = 0; i<questions.size(); i++){
            long long ans = solve(questions, i, dp);
            result = max(result, ans);
        }
        return result;
    }
};