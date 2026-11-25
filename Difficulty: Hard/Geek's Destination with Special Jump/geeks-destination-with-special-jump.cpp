class Solution {
     const long long MOD = 1000000007;

     // Calculates minimum time to reach or pass d using a jump of length j
     long long getTime(long long a, long long b, long long d, long long j) {
         long long remaining = d - j;
         if (remaining <= 0) return 1;
         if (remaining <= a) return remaining + 1;

         long long net = a - b;
         long long cycles = (remaining - a + net - 1) / net;
         return remaining + 2LL * b * cycles + 1;
     }

     // Calculates the sum of all unreachable ("missing") time values up to t
     long long missingSum(long long a, long long b, long long t) {
         long long first = a + 2;
         long long cycleTime = a + b;
         if (t < first) return 0;

         long long count = (t - first) / cycleTime + 1;
         long long last = first + (count - 1) * cycleTime;

         long long inv2 = (MOD + 1) / 2;
         long long term1 = (b % MOD) * (count % MOD) % MOD;
         term1 = term1 * ((first + last) % MOD) % MOD;

         long long term2 = (count % MOD) * ((2LL * b - 1) % MOD) % MOD;
         term2 = term2 * ((2LL * b) % MOD) % MOD;
         term2 = term2 * inv2 % MOD;

         return (term1 + term2) % MOD;
     }

     // Calculates prefix sum of all valid minimum times up to t
     long long prefixSum(long long a, long long b, long long t) {
         long long inv2 = (MOD + 1) / 2;
         long long total = (t % MOD) * ((t + 1) % MOD) % MOD;
         total = total * inv2 % MOD;
         return (total - missingSum(a, b, t) + MOD) % MOD;
     }

   public:
     int minTime(int a, int b, int d, int l, int r) {
         long long t1 = getTime(a, b, d, l);
         long long t2 = getTime(a, b, d, r + 1);
         return (prefixSum(a, b, t1) - prefixSum(a, b, t2) + MOD) % MOD;
     }
 };
