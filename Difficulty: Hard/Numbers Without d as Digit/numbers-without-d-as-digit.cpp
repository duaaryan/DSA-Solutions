class Solution {
    std::vector<int> digits;
    int dp[12][2][2];
    int target_d;

    int solve(int index, bool tight, bool leading_zero) {
        // Base case: all digits have been placed
        if (index == digits.size()) {
            // If it's a completely empty number (all leading zeros), it represents 0.
            // Since the problem asks for numbers from 1 to n, 0 is invalid.
            return leading_zero ? 0 : 1;
        }

        // Return memoized result if already computed
        if (dp[index][tight][leading_zero] != -1) {
            return dp[index][tight][leading_zero];
        }

        // Define upper bound for the current digit
        int limit = tight ? digits[index] : 9;
        int ans = 0;

        for (int i = 0; i <= limit; i++) {
            // Skip the digit if it matches 'd'
            if (i == target_d) {
                // Exception: if d is 0 and it's a leading zero, it is allowed
                if (target_d == 0 && leading_zero) {
                    // Safe to proceed
                } else {
                    continue; 
                }
            }

            bool next_tight = tight && (i == limit);
            bool next_leading_zero = leading_zero && (i == 0);

            ans += solve(index + 1, next_tight, next_leading_zero);
        }

        return dp[index][tight][leading_zero] = ans;
    }

public:
    int countWithout(int n, int d) {
        digits.clear();
        target_d = d;
        std::memset(dp, -1, sizeof(dp));

        // Extract digits of n
        int temp = n;
        while (temp > 0) {
            digits.push_back(temp % 10);
            temp /= 10;
        }
        std::reverse(digits.begin(), digits.end());

        // Start DP from index 0 with tight=true and leading_zero=true
        return solve(0, true, true);
    }
};
