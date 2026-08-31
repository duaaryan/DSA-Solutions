class Solution {
public:
    int palindromicStrings(int n, int k) {
        long long MOD = 1e9 + 7;
        long long total_count = 0;

        // Iterate through all possible lengths from 1 to n
        for (int L = 1; L <= n; L++) {
            // Calculate the number of unique characters needed for length L
            int c = (L + 1) / 2;

            // If we need more unique characters than available in the alphabet, 
            // no valid palindrome can be formed for this length or longer lengths.
            if (c > k) {
                continue;
            }

            // Calculate P(k, c) = k * (k-1) * ... * (k-c+1)
            long long permutations = 1;
            for (int i = 0; i < c; i++) {
                permutations = (permutations * (k - i)) % MOD;
            }

            // Add to total sum
            total_count = (total_count + permutations) % MOD;
        }

        return total_count;
    }
};