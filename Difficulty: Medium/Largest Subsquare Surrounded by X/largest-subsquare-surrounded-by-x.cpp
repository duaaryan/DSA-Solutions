class Solution {
  public:
    int largestSubsquare(vector<vector<char>>& mat) {
        int n = mat.size();
        if (n == 0) return 0;

        // top[i][j] stores consecutive 'X's vertical up to mat[i][j]
        // left[i][j] stores consecutive 'X's horizontal up to mat[i][j]
        vector<vector<int>> top(n, vector<int>(n, 0));
        vector<vector<int>> left(n, vector<int>(n, 0));

        // Fill the DP tables
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 'X') {
                    top[i][j] = (i == 0) ? 1 : top[i - 1][j] + 1;
                    left[i][j] = (j == 0) ? 1 : left[i][j - 1] + 1;
                }
            }
        }

        int max_size = 0;

        // Check for the largest square from bottom-right to top-left
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                // Find the maximum possible side length bounded by the current cell
                int small = min(top[i][j], left[i][j]);

                // Prune: only check sizes larger than the currently found max_size
                while (small > max_size) {
                    // Check top edge and left edge of the square matrix
                    if (left[i - small + 1][j] >= small && top[i][j - small + 1] >= small) {
                        max_size = small;
                        break; // Found the largest for this cell, move to the next cell
                    }
                    small--;
                }
            }
        }

        return max_size;
    }
};
