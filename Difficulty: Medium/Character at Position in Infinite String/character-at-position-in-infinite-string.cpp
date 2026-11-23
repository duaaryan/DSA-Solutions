class Solution {
  public:
    char posInfinite(string &s, int pos) {
        long long n = s.length();
        long long p = pos;

        // Store lengths at each step: lengths[i] is length after step i
        vector<long long> lengths;
        lengths.push_back(n);

        int step = 0;
        while (lengths.back() < p) {
            step++;
            long long next_len = 2 * lengths.back() + step;
            lengths.push_back(next_len);
        }

        // Trace back from the final step to step 1
        for (int i = step; i >= 1; i--) {
            long long prev_len = lengths[i - 1];
            long long curr_len = lengths[i];

            if (p <= prev_len) {
                // In the first half (s_{i-1}), position doesn't change
                continue;
            } else if (p <= prev_len + i) {
                // In the middle section of '$' characters
                return '$';
            } else {
                // In the reversed second half: map back to s_{i-1}
                p = curr_len - p + 1;
            }
        }

        // Return the 0-indexed character from the original string
        return s[p - 1];
    }
};
