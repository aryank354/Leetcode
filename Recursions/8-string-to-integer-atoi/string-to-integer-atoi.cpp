class Solution {
public:
    
void helperAtoi(int n, const string &s, long long &ans, bool is_negative) {
    if (n >= s.size() || !isdigit(s[n])) return;
    
    int digit = s[n] - '0';
    
    // Check for overflow/underflow before updating ans
    if (!is_negative) {
        if (ans > (long long)INT_MAX / 10 ||
           (ans == (long long)INT_MAX / 10 && digit > 7)) {
            ans = INT_MAX;
            return;
        }
    } else {
        if (ans > (long long)INT_MAX / 10 ||
           (ans == (long long)INT_MAX / 10 && digit > 8)) {
            ans = (long long)INT_MAX + 1;  
            return;
        }
    }
    
    ans = ans * 10 + digit;
    helperAtoi(n + 1, s, ans, is_negative);
}

    int myAtoi(string s) {
    int n = 0;
    long long ans = 0;
    bool is_negative = false;

    while(n < s.size() && s[n] == ' ') {
        n++;
    }
    
    if(n < s.size() && (s[n] == '-' || s[n] == '+')) {
        is_negative = (s[n] == '-');
        n++;
    }
    
    helperAtoi(n, s, ans, is_negative);
    
    if(is_negative) {
        if(ans > (long long)INT_MAX + 1) {
            return INT_MIN;
        }
        return -ans;
    } else {
        if(ans > INT_MAX) {
            return INT_MAX;
        }
        return ans;
    }
}

};