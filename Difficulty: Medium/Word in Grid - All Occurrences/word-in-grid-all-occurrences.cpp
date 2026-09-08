#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> searchWord(vector<vector<char>>& mat, string word) {
        int n = mat.size();
        int m = mat[0].size();
        int len = word.length();
        vector<vector<int>> result;

        // The 8 possible directions: 2 horizontal, 2 vertical, 4 diagonal
        int x[] = {-1, -1, -1,  0, 0,  1, 1, 1};
        int y[] = {-1,  0,  1, -1, 1, -1, 0, 1};

        // Traverse every cell in the grid
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {

                // Only start searching if the first character matches
                if (mat[r][c] == word[0]) {
                    bool found = false;

                    // Search in all 8 directions
                    for (int dir = 0; dir < 8; ++dir) {
                        int k;
                        int curr_r = r + x[dir];
                        int curr_c = c + y[dir];

                        // Check remaining characters of the word
                        for (k = 1; k < len; ++k) {
                            // Break if out of bounds
                            if (curr_r < 0 || curr_r >= n || curr_c < 0 || curr_c >= m) {
                                break;
                            }
                            // Break if character doesn't match
                            if (mat[curr_r][curr_c] != word[k]) {
                                break;
                            }

                            // Move further in the same straight-line direction
                            curr_r += x[dir];
                            curr_c += y[dir];
                        }

                        // If all characters matched successfully
                        if (k == len) {
                            found = true;
                            break; // Stop searching other directions for this cell
                        }
                    }

                    // If the word was found starting at (r, c), record it
                    if (found) {
                        result.push_back({r, c});
                    }
                }

            }
        }

        return result;
    }
};
