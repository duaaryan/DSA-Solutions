class Solution {
  public:
    int countBT(int h) {
        if (h == 0 || h == 1) {
            return 1;
        }

        long long MOD = 1000000007;
        long long prev2 = 1; // count(0)
        long long prev1 = 1; // count(1)
        long long curr = 0;

        for (int i = 2; i <= h; i++) {
            long long square_term = (prev1 * prev1) % MOD;
            long long mixed_term = (2 * prev1 * prev2) % MOD;

            curr = (square_term + mixed_term) % MOD;

            // Shift values for the next iteration
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};
