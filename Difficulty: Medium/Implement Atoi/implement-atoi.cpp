class Solution {
public:
    int myAtoi(string &s) {
        int i = 0;
        int n = s.size();

        // Rule 1: leading spaces skip
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Rule 2: sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // Rule 3 aur 4: digits padho aur overflow check karo
        long long num = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');

            if (sign * num > INT_MAX) return INT_MAX;
            if (sign * num < INT_MIN) return INT_MIN;

            i++;
        }

        return (int)(sign * num);
    }
};