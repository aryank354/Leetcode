class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> group(26, -1);  // group[i] indicates group ID of character 'a' + i
        int groupCount = 0;
        int length = s1.size();

        // Step 1: Group equivalent characters
        for (int i = 0; i < length; i++) {
            int char1 = s1[i] - 'a';
            int char2 = s2[i] - 'a';

            if (char1 == char2) continue;

            if (group[char1] == -1 && group[char2] == -1) {
                group[char1] = group[char2] = groupCount++;
            } else if (group[char1] == -1) {
                group[char1] = group[char2];
            } else if (group[char2] == -1) {
                group[char2] = group[char1];
            } else {
                // Merge groups
                int g1 = group[char1];
                int g2 = group[char2];
                if (g1 != g2) {
                    for (int j = 0; j < 26; j++) {
                        if (group[j] == g1) {
                            group[j] = g2;
                        }
                    }
                }
            }
        }

        // Step 2: Map each group to its smallest character
        map<int, char> groupToChar;
        for (int i = 0; i < 26; i++) {
            int g = group[i];
            if (g == -1) continue;
            char currentChar = 'a' + i;
            if (groupToChar.find(g) == groupToChar.end()) {
                groupToChar[g] = currentChar;
            } else {
                groupToChar[g] = min(groupToChar[g], currentChar);
            }
        }

        // Step 3: Build result from baseStr
        string result = "";
        for (char c : baseStr) {
            int groupId = group[c - 'a'];
            result += (groupId == -1) ? c : groupToChar[groupId];
        }

        return result;
    }
};