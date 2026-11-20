class Solution {
  public:
    int minFlips(string &s) {
        int n = s.size();
        int flipsStartWithZero = 0;

        for (int i = 0; i < n; i++) {
            // Expected character if string starts with '0':
            // '0' at even indices, '1' at odd indices
            char expected = (i % 2 == 0) ? '0' : '1';

            if (s[i] != expected) {
                flipsStartWithZero++;
            }
        }

        // Compare flips needed for "0101..." vs "1010..."
        return min(flipsStartWithZero, n - flipsStartWithZero);
    }
};
