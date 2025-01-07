class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> result;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                // Check if words[i] is a substring of words[j]
                if (words[j].find(words[i]) != string::npos) {
                    // Add to result only if it's not already present
                    if (find(result.begin(), result.end(), words[i]) == result.end()) {
                        result.push_back(words[i]);
                    }
                    break; // No need to check further for this word
                }
            }
        }

        return result;
    }
};
