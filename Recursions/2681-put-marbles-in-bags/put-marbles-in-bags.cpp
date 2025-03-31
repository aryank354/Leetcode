class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<long long>sum(n-1, 0);
        for(int i = 0; i < n - 1; i++){
            sum[i] = weights[i] + weights[i + 1];
        }
        long long maxi = 0;
        long long mini = 0;
        sort(sum.begin(), sum.end());

        for(int i = 0; i < k-1; i++){
            maxi += sum[n-i-2];
            mini += sum[i];
        }

        return maxi - mini;
    }
};