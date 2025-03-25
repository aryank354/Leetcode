class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int m = rectangles.size();
        
        auto validCutExists = [&](int startIndex, int endIndex) -> bool {
            vector<int> starts, ends;
            set<int> candSet;
            for (auto &r : rectangles) {
                int s = r[startIndex], e = r[endIndex];
                starts.push_back(s);
                ends.push_back(e);
                candSet.insert(s);
                candSet.insert(e);
            }
            sort(starts.begin(), starts.end());
            sort(ends.begin(), ends.end());
            vector<int> candidates(candSet.begin(), candSet.end());
            
            
            vector<int> validCuts;
            for (int c : candidates) {
                
                int countStarts = lower_bound(starts.begin(), starts.end(), c) - starts.begin();
                int countEnds = upper_bound(ends.begin(), ends.end(), c) - ends.begin(); 
                if (countStarts == countEnds) {
                    validCuts.push_back(c);
                }
            }
            
            if (validCuts.size() < 2) return false; 
            auto countEndLE = [&](int c) -> int {
                return upper_bound(ends.begin(), ends.end(), c) - ends.begin();
            };
            auto countStartGE = [&](int c) -> int {
                return starts.end() - lower_bound(starts.begin(), starts.end(), c);
            };
            
            
            for (int i = 0; i < (int)validCuts.size(); i++) {
                int c1 = validCuts[i];
                int group1 = countEndLE(c1);
                if (group1 <= 0) continue;
                for (int j = i+1; j < (int)validCuts.size(); j++) {
                    int c2 = validCuts[j];
                    int group3 = countStartGE(c2);
                    if (group3 <= 0) continue;
                    int group2 = m - group1 - group3;
                    if (group2 > 0)
                        return true;
                }
            }
            return false;
        };
        
        
        if (validCutExists(1, 3)) return true;
        
        if (validCutExists(0, 2)) return true;
        
        return false;
    }
};
