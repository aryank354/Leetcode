class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> graph(n);
        
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> bobTime(n, -1);
        vector<bool> visited(n, false);
        
        function<int(int, int, int)> findBobPath = [&](int node, int parent, int time) {
            if (node == 0) return time;
            bobTime[node] = time;
            for (int neighbor : graph[node]) {
                if (neighbor != parent) {
                    int res = findBobPath(neighbor, node, time + 1);
                    if (res != -1) return res;
                }
            }
            bobTime[node] = -1;
            return -1;
        };
        
        findBobPath(bob, -1, 0);
        
        function<int(int, int, int)> dfs = [&](int node, int parent, int time) {
            int income = (bobTime[node] == -1 || bobTime[node] > time) ? amount[node] : (bobTime[node] == time ? amount[node] / 2 : 0);
            
            int maxProfit = INT_MIN;
            bool isLeaf = true;
            
            for (int neighbor : graph[node]) {
                if (neighbor != parent) {
                    isLeaf = false;
                    maxProfit = max(maxProfit, dfs(neighbor, node, time + 1));
                }
            }
            
            return income + (isLeaf ? 0 : maxProfit);
        };
        
        return dfs(0, -1, 0);
    }
};