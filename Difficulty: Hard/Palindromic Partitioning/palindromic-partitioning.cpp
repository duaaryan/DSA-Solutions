class Solution {
public:
    int palPartition(string str) {
        int n = str.length();
        if (n <= 1) return 0;

        // pal[i][j] will be true if substring str[i..j] is a palindrome
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Single characters are always palindromes
        for (int i = 0; i < n; i++) {
            pal[i][i] = true;
        }

        // Fill the palindrome table
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (str[i] == str[j]) {
                    if (len == 2 || pal[i + 1][j - 1]) {
                        pal[i][j] = true;
                    }
                }
            }
        }

        // minCuts[i] stores the minimum cuts needed for substring str[0..i]
        vector<int> minCuts(n, 0);

        for (int i = 0; i < n; i++) {
            if (pal[0][i]) {
                minCuts[i] = 0; // If str[0..i] is a palindrome, 0 cuts needed
            } else {
                int cuts = i; // Maximum possible cuts
                for (int j = 0; j < i; j++) {
                    if (pal[j + 1][i]) {
                        cuts = min(cuts, minCuts[j] + 1);
                    }
                }
                minCuts[i] = cuts;
            }
        }

        return minCuts[n - 1];
    }
};
