#include <vector>

using namespace std;

class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2 * n - 1, 0);
        vector<bool> used(n + 1, false);
        backtrack(result, used, n, 0);
        return result;
    }

private:
    bool backtrack(vector<int>& result, vector<bool>& used, int n, int index) {
        if (index == result.size()) return true; 

        if (result[index] != 0) return backtrack(result, used, n, index + 1);

        for (int num = n; num >= 1; num--) {
            if (used[num]) continue;

            if (num == 1) { 
                result[index] = 1;
                used[1] = true;
                if (backtrack(result, used, n, index + 1)) return true;
                result[index] = 0;
                used[1] = false;
            } else {
                int secondPos = index + num;
                if (secondPos < result.size() && result[secondPos] == 0) {
                    result[index] = result[secondPos] = num;
                    used[num] = true;

                    if (backtrack(result, used, n, index + 1)) return true;

                    result[index] = result[secondPos] = 0;
                    used[num] = false;
                }
            }
        }
        return false;
    }
};
