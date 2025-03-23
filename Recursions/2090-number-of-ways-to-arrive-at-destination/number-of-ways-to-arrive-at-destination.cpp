class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;
        vector<vector<pair<int, int>>> graph(n);
        for(auto &road : roads) {
            int u = road[0], v = road[1], t = road[2];
            graph[u].push_back({v, t});
            graph[v].push_back({u, t});
        }
        
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        
        priority_queue<pair<long long, int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0, 0});
        
        while(!pq.empty()){
            auto [curDist, u] = pq.top();
            pq.pop();
            
            if(curDist > dist[u]) continue;
            
            for(auto &[v, t] : graph[u]){
                long long newDist = curDist + t;
                if(newDist < dist[v]){
                    dist[v] = newDist;
                    ways[v] = ways[u];
                    pq.push({newDist, v});
                } 
                else if(newDist == dist[v]){
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};
