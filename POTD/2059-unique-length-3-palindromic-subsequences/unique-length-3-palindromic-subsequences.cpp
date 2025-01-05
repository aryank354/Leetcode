class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        int result = 0;

        // Step 1: Create a set of unique characters in the string
        unordered_set<char> uniqueChars(s.begin(), s.end());

        // Step 2: For each unique character, find palindromic subsequences
        for (char letter : uniqueChars) {
            int leftIndex = -1, rightIndex = -1;

            // Find the first and last occurrence of the character
            for (int i = 0; i < n; i++) {
                if (s[i] == letter) {
                    if (leftIndex == -1) {
                        leftIndex = i;
                    }
                    rightIndex = i;
                }
            }

            // If valid palindromic bounds exist, count unique characters in between
            if (leftIndex != -1 && rightIndex != -1 && rightIndex > leftIndex + 1) {
                unordered_set<char> middleChars;
                for (int i = leftIndex + 1; i < rightIndex; i++) {
                    middleChars.insert(s[i]);
                }

                // Add the count of unique middle characters to the result
                result += middleChars.size();
            }
        }

        return result;
    }
};
