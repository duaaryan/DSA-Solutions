class Solution {
private:
    bool dfs(vector<vector<char>>& mat, string& word, int r, int c, int index) {
        // Base case: If we matched all characters in the word
        if (index == word.length()) {
            return true;
        }

        // Check boundary conditions and character mismatch
        if (r < 0 || r >= mat.size() || c < 0 || c >= mat[0].size() || mat[r][c] != word[index]) {
            return false;
        }

        // Save original character and mark cell as visited
        char temp = mat[r][c];
        mat[r][c] = '#';

        // Explore all 4 adjacent directions (Down, Up, Right, Left)
        bool found = dfs(mat, word, r + 1, c, index + 1) ||
                     dfs(mat, word, r - 1, c, index + 1) ||
                     dfs(mat, word, r, c + 1, index + 1) ||
                     dfs(mat, word, r, c - 1, index + 1);

        // Backtrack: Restore original character
        mat[r][c] = temp;

        return found;
    }

public:
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        int rows = mat.size();
        int cols = mat[0].size();

        // Traverse the entire matrix to find the starting letter
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == word[0]) {
                    // Start DFS search from this cell
                    if (dfs(mat, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
