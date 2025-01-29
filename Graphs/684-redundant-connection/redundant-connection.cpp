class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
        
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int rootU = find(u, parent);
            int rootV = find(v, parent);
            if (rootU == rootV) {
                return edge;
            }
            parent[rootV] = rootU;
        }
        return {}; // This line is theoretically unreachable given the problem constraints.
    }
    
private:
    int find(int x, vector<int>& parent) {
        if (parent[x] != x) {
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }
};