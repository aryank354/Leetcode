#include <string>
#include <vector>
#include <array>
#include <cassert>
#include <algorithm>

class Solution {
public:
    long long countOfSubstrings(std::string word, int k) {
        int n = word.size();
        // vowels set for quick checking.
        auto isVowel = [&](char c) {
            return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
        };

        // Precompute prefix frequency for vowels.
        // For convenience, we use an array of size 5 for vowels in order: a,e,i,o,u.
        auto vowelIndex = [&](char c) -> int {
            if(c=='a') return 0;
            if(c=='e') return 1;
            if(c=='i') return 2;
            if(c=='o') return 3;
            if(c=='u') return 4;
            return -1;
        };
        std::vector<std::array<int, 5>> pref(n+1);
        pref[0] = {0,0,0,0,0};
        for (int i = 0; i < n; i++) {
            pref[i+1] = pref[i];
            if(isVowel(word[i])) {
                int idx = vowelIndex(word[i]);
                pref[i+1][idx]++;
            }
        }
        
        // Helper to check if substring [L, R] (inclusive) has every vowel.
        auto hasAllVowels = [&](int L, int R) -> bool {
            for (int v = 0; v < 5; v++) {
                if(pref[R+1][v] - pref[L][v] <= 0) return false;
            }
            return true;
        };
        
        long long ans = 0;
        
        // We'll treat two cases: k > 0 and k == 0 separately.
        if(k > 0) {
            // Gather all indices of consonants.
            std::vector<int> cons;
            for (int i = 0; i < n; i++) {
                if(!isVowel(word[i])) {
                    cons.push_back(i);
                }
            }
            // If there are not enough consonants overall to have exactly k, answer is 0.
            if(cons.size() < (size_t)k) return 0LL;
            
            // For each block defined by k consecutive consonants.
            // Let the block be determined by cons[i] .. cons[i+k-1].
            for (int i = 0; i <= (int)cons.size() - k; i++) {
                // Determine left-bound range:
                int L_low = (i == 0 ? 0 : cons[i-1] + 1);
                int L_high = cons[i]; // left must be <= first consonant in block.
                
                // Determine right-bound range:
                int R_low = cons[i+k-1]; // right must be >= last consonant in block.
                int R_high = (i+k < cons.size() ? cons[i+k] - 1 : n - 1);
                
                // For each valid left boundary in [L_low, L_high]
                for (int L = L_low; L <= L_high; L++) {
                    // Binary search for smallest R in [R_low, R_high] with hasAllVowels(L,R)==true.
                    int lo = R_low, hi = R_high, pos = -1;
                    while(lo <= hi) {
                        int mid = lo + (hi - lo) / 2;
                        if(hasAllVowels(L, mid)) {
                            pos = mid;
                            hi = mid - 1;
                        } else {
                            lo = mid + 1;
                        }
                    }
                    if(pos != -1) {
                        // All substrings [L, R] with R in [pos, R_high] are valid.
                        ans += (long long)(R_high - pos + 1);
                    }
                }
            }
        } else {
            // k == 0: we need substrings with no consonants.
            // They occur in maximal segments with only vowels.
            int start = 0;
            while(start < n) {
                if(!isVowel(word[start])) { 
                    start++; 
                    continue;
                }
                int end = start;
                while(end < n && isVowel(word[end])) end++;
                // Now consider segment [start, end-1] which is all vowels.
                // For each starting index L in this segment, find minimal R with all vowels.
                for (int L = start; L < end; L++) {
                    int lo = L, hi = end - 1, pos = -1;
                    while(lo <= hi) {
                        int mid = lo + (hi - lo) / 2;
                        if(hasAllVowels(L, mid)) {
                            pos = mid;
                            hi = mid - 1;
                        } else {
                            lo = mid + 1;
                        }
                    }
                    if(pos != -1) {
                        ans += (long long)(end - pos);
                    }
                }
                start = end;
            }
        }
        
        return ans;
    }
};
