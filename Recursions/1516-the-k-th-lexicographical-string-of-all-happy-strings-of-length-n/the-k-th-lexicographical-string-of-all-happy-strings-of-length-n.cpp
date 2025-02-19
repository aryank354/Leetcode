class Solution {
public:
    void generateHappyStrings(int n, string current, vector<string>& result, int& k) {
        if (current.length() == n) {
            result.push_back(current);
            if (result.size() == k) return; // Stop early if k strings are generated
            return;
        }
        
        for (char ch : {'a', 'b', 'c'}) {
            if (current.empty() || current.back() != ch) {
                generateHappyStrings(n, current + ch, result, k);
                if (result.size() == k) return; // Stop recursion early
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> happyStrings;
        generateHappyStrings(n, "", happyStrings, k);
        return (happyStrings.size() >= k) ? happyStrings[k - 1] : "";
    }
};
