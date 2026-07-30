class Solution {
  public:
    int countSubsets(vector<int> &arr) {
        // code here
        
   long long MOD = 1e9 + 7;
        // The 10 prime numbers up to 30
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        
        // Count frequencies of each number in the input array
        vector<int> count(31, 0);
        for (int x : arr) {
            count[x]++;
        }
        
        // Precompute bitmasks for numbers from 2 to 30
        vector<int> mask(31, 0);
        for (int i = 2; i <= 30; i++) {
            int current_mask = 0;
            bool valid = true;
            for (int j = 0; j < 10; j++) {
                if (i % (primes[j] * primes[j]) == 0) {
                    valid = false;
                    break;
                }
                if (i % primes[j] == 0) {
                    current_mask |= (1 << j);
                }
            }
            mask[i] = valid ? current_mask : -1;
        }
        
        // dp[mask] stores the number of valid subsets with prime composition 'mask'
        vector<long long> dp(1024, 0);
        dp[0] = 1; // Base case: 1 way to make an empty subset
        
        // Iterating through all numbers from 2 to 30
        for (int i = 2; i <= 30; i++) {
            if (count[i] == 0 || mask[i] == -1) continue;
            
            // Traverse masks in reverse to prevent using the same element multiple times
            for (int m = 1023; m >= 0; m--) {
                if ((m & mask[i]) == 0) { // Check if no prime factors are shared
                    dp[m | mask[i]] = (dp[m | mask[i]] + dp[m] * count[i]) % MOD;
                }
            }
        }
        
        // Sum up all valid combinations (excluding empty subset mask 0)
        long long total_subsets = 0;
        for (int m = 1; m < 1024; m++) {
            total_subsets = (total_subsets + dp[m]) % MOD;
        }
        
        // Factor in the contribution of all 1s: 2^count[1]
        long long power_of_two = 1;
        for (int i = 0; i < count[1]; i++) {
            power_of_two = (power_of_two * 2) % MOD;
        }
        
        total_subsets = (total_subsets * power_of_two) % MOD;
        return total_subsets;
    }
};