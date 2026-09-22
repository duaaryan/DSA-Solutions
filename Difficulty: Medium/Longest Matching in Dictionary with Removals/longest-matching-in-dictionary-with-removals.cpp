class Solution {
public:
    string findLongestWord(string &s, vector<string> &d) {
        int n = s.length();
        // next_pos[i][c] stores the first occurrence of character c at or after index i
        vector<vector<int>> next_pos(n + 1, vector<int>(26, -1));

        // Build the next_pos table from right to left
        for (int i = n - 1; i >= 0; --i) {
            for (int c = 0; c < 26; ++c) {
                next_pos[i][c] = next_pos[i + 1][c];
            }
            next_pos[i][s[i] - 'a'] = i;
        }

        string res = "";

        // Check each word in the dictionary
        for (const string &word : d) {
            int curr_idx = 0;
            bool is_subsequence = true;

            for (char ch : word) {
                if (curr_idx >= n) {
                    is_subsequence = false;
                    break;
                }
                int nxt = next_pos[curr_idx][ch - 'a'];
                if (nxt == -1) {
                    is_subsequence = false;
                    break;
                }
                curr_idx = nxt + 1; // Move past the matched character
            }

            // If the word is a valid subsequence, check if it fits the criteria
            if (is_subsequence) {
                if (word.length() > res.length()) {
                    res = word;
                } else if (word.length() == res.length() && word < res) {
                    res = word;
                }
            }
        }

        return res;
    }
};
