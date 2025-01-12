class Solution {
public:
    bool canConstruct(string s, int k) {
        // If k is greater than the length of s, it's impossible
        if (k > s.length()) {
            return false;
        }
        
        // Count the frequency of each character
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        // Count the number of characters with odd frequencies
        int oddCount = 0;
        for (auto& pair : freq) {
            if (pair.second % 2 == 1) {
                oddCount++;
            }
        }
        
        // Check if we can construct k palindromes
        return oddCount <= k;
    }
};