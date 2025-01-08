class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        // Helper function to check if str1 is both a prefix and suffix of str2
        auto isPrefixAndSuffix = [](const string& str1, const string& str2) {
            return str2.find(str1) == 0 && str2.rfind(str1) == str2.size() - str1.size();
        };

        int count = 0;

        // Nested loops to check all pairs (i, j) where i < j
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }

        return count;
    }
};