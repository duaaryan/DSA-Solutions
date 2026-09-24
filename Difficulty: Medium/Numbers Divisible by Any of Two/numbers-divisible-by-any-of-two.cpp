class Solution {
private:
    long long getSum(long long n, long long k) {
        long long m = n / k;
        return (k * m * (m + 1)) / 2;
    }

public:
    int sumOfSeries(long long n, long long a, long long b) {
        long long MOD = 1e9 + 7;

        long long gcd_val = std::gcd(a, b);

        // Prevent overflow during LCM calculation
        long long lcm_val = (a / gcd_val);
        if (lcm_val > n / b) {
            lcm_val = n + 1; // Any value greater than n is sufficient
        } else {
            lcm_val *= b;
        }

        long long sum_a = getSum(n, a);
        long long sum_b = getSum(n, b);
        long long sum_lcm = (lcm_val <= n) ? getSum(n, lcm_val) : 0;

        long long ans = (sum_a + sum_b - sum_lcm) % MOD;
        if (ans < 0) ans += MOD; // Ensure non-negative modulo result

        return ans;
    }
};
