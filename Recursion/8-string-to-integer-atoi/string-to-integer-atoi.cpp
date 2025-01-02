// normal method 

// class Solution {
// public:
//     int myAtoi(string s) {
//         int i = 0, n = s.size();
//         // Step 1: Ignore leading whitespace
//         while (i < n && s[i] == ' ') {
//             i++;
//         }

//         // Step 2: Check for optional sign
//         int sign = 1;
//         if (i < n && (s[i] == '+' || s[i] == '-')) {
//             sign = (s[i] == '-') ? -1 : 1;
//             i++;
//         }

//         // Step 3: Convert digits to integer
//         long long ans = 0; // Use long long to handle overflow
//         while (i < n && s[i] >= '0' && s[i] <= '9') {
//             ans = ans * 10 + (s[i] - '0');
//             // Step 4: Clamp to the range [-2^31, 2^31 - 1]
//             if (ans * sign > INT_MAX) {
//                 return INT_MAX;
//             }
//             if (ans * sign < INT_MIN) {
//                 return INT_MIN;
//             }
//             i++;
//         }

//         return static_cast<int>(ans * sign);
//     }
// };

// recursive method

class Solution {
public:
    // Helper function for recursion
    long long recAtoi(const string &s, int index, long long ans, int sign) {
        // Base case: Stop recursion if index is out of bounds or non-digit is found
        if (index >= s.size() || s[index] < '0' || s[index] > '9') {
            return ans*sign ;
        }

        // Convert the current character to a digit and update the result
        ans = ans * 10 + (s[index] - '0');

        // Clamp the result to prevent overflow
        if (sign * ans > INT_MAX) {
            return INT_MAX;
        }
        if (sign * ans < INT_MIN) {
            return INT_MIN;
        }

        // Recur for the next character
        return recAtoi(s, index + 1, ans, sign);
    }

    int myAtoi(string s) {
        int i = 0, n = s.size();
        int sign = 1; // Default sign is positive

        // Step 1: Ignore leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Check for optional sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Recursively calculate the integer value
        long long result = recAtoi(s, i, 0, sign);

        // Step 4: Return the final result within the 32-bit signed integer range
        return static_cast<int>(result);
    }
};


