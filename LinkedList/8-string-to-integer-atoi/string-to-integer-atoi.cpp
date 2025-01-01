class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        // Step 1: Ignore leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Check for optional sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Convert digits to integer
        long long ans = 0; // Use long long to handle overflow
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            ans = ans * 10 + (s[i] - '0');
            // Step 4: Clamp to the range [-2^31, 2^31 - 1]
            if (ans * sign > INT_MAX) {
                return INT_MAX;
            }
            if (ans * sign < INT_MIN) {
                return INT_MIN;
            }
            i++;
        }

        return static_cast<int>(ans * sign);
    }
};
