class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int a) {
        if (parent[a] != a)
            parent[a] = find(parent[a]);
        return parent[a];
    }
    
    bool unionSet(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
        return true;
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        const int BITS = 18;
        int full_mask = (1 << BITS) - 1;
  
        vector<int> removable(n, 0);
        
        DSU dsu(n);
        for (const auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            removable[u] |= ((~w) & full_mask);
            removable[v] |= ((~w) & full_mask);
            dsu.unionSet(u, v);
        }
        
        vector<int> comp_mask(n, 0);
        for (int v = 0; v < n; v++) {
            int root = dsu.find(v);
            comp_mask[root] |= removable[v];
        }
        

        vector<int> ans;
        for (const auto &q : query) {
            int s = q[0], t = q[1];
            if (dsu.find(s) != dsu.find(t)) {
                ans.push_back(-1);
            } else {
                int root = dsu.find(s);
                ans.push_back((~comp_mask[root]) & full_mask);
            }
        }
        
        return ans;
    }
};
