class Solution {
public:
bool areAlmostEqual(string s1, string s2) {
    if (s1 == s2) return true; // If both strings are already equal

    vector<int> diff; // Stores indices where s1 and s2 differ

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            diff.push_back(i);
            if (diff.size() > 2) return false; // More than 2 differences -> impossible with one swap
        }
    }

    if (diff.size() != 2) return false; // If there are not exactly 2 differences, swapping won't work

    // Check if swapping the two different characters makes the strings equal
    return s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]];
}
};