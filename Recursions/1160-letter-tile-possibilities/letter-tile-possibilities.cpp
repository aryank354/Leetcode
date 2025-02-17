class Solution {
public:

void backtrack(unordered_map<char, int>& freq, int& count, int length) {
    for (auto& [ch, val] : freq) {
        if (val > 0) {
            freq[ch]--;
            count++;
            backtrack(freq, count, length + 1);
            freq[ch]++;
        }
    }
}

int numTilePossibilities(string tiles) {
    unordered_map<char, int> freq;
    
    for (char ch : tiles) {
        freq[ch]++;
    }
    
    int count = 0;
    backtrack(freq, count, 0);
    return count;
}
};