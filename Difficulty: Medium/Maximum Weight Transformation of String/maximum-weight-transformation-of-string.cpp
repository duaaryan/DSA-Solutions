class Solution {
public:
    int getMaxWeight(string &s) {
        int n = s.length();
        if (n == 0) return 0;
        if (n == 1) return 1; // Single standalone character

        // Base cases
        int prev2 = 0; // dp[i-2]
        int prev1 = 1; // dp[i-1] initialization for single character string

        // Calculate for the second character manually to bootstrap the loop
        int curr = prev1 + 1;
        if ((s[0] == 'A' && s[1] == 'B') || (s[0] == 'B' && s[1] == 'A')) {
            curr = max(curr, prev2 + 4);
        } else {
            curr = max(curr, prev2 + 3);
        }

        prev2 = prev1;
        prev1 = curr;

        // Iterate through the rest of the string
        for (int i = 2; i < n; i++) {
            // Choice 1: Do not pair the current character
            curr = prev1 + 1;

            // Choice 2: Pair with the previous character
            if ((s[i-1] == 'A' && s[i] == 'B') || (s[i-1] == 'B' && s[i] == 'A')) {
                curr = max(curr, prev2 + 4);
            } else {
                curr = max(curr, prev2 + 3);
            }

            // Move state forward
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
