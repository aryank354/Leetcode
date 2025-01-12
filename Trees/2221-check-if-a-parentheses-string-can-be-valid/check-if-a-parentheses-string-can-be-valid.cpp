class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0) return false; // Odd length cannot form a valid string
        
        // Left-to-right pass
        int open = 0, balance = 0;
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '1') {
                if (s[i] == '(') ++open;
                else --open;
            } else {
                ++balance; // Unlocked position can be used as '(' or ')'
            }
            if (open + balance < 0) return false; // Too many ')'
        }
        
        // Right-to-left pass
        open = 0, balance = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (locked[i] == '1') {
                if (s[i] == ')') ++open;
                else --open;
            } else {
                ++balance; // Unlocked position can be used as '(' or ')'
            }
            if (open + balance < 0) return false; // Too many '('
        }
        
        return true;
    }
};
