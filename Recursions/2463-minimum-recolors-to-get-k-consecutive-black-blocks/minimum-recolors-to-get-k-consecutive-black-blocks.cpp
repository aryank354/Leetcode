class Solution {
public:
    int minimumRecolors(string b, int k) {
        int n = b.size();
        
        int w_count = 0, min_w;

        for (int j = 0; j < k; j++) {
            if (b[j] == 'W') w_count++;
        }
        min_w = w_count; 
        for (int j = k; j < n; j++) {
            if (b[j - k] == 'W') w_count--;
            
            if (b[j] == 'W') w_count++;

            min_w = min(min_w, w_count);
        }

        return min_w;
    }
};
