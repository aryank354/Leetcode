class Solution {
public:

    bool isValidPartition(string squareStr, int index, int currentSum, int target) {
        if (index == squareStr.size()) {
            return currentSum == target;
        }

        int num = 0;
        for (int j = index; j < squareStr.size(); j++) {
            num = num * 10 + (squareStr[j] - '0'); 
            if (currentSum + num > target) break;  
            if (isValidPartition(squareStr, j + 1, currentSum + num, target)) {
                return true;
            }
        }
        return false;
    }

    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            int square = i * i;
            string squareStr = to_string(square);
            if (isValidPartition(squareStr, 0, 0, i)) {
                sum += square;
            }
        }
        return sum;
    }
};
