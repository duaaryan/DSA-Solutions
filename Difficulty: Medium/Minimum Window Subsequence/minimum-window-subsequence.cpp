class Solution {
public:
    string minWindow(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();

        if (m == 0 || m > n) {
            return "";
        }

        // n means the letter does not appear at or after this index.
        vector<vector<int>> nextPos(n + 1, vector<int>(26, n));

        for (int i = n - 1; i >= 0; i--) {
            nextPos[i] = nextPos[i + 1];
            nextPos[i][s1[i] - 'a'] = i;
        }

        int bestStart = 0;
        int bestLength = n + 1;

        for (int start = 0; start < n; start++) {
            if (s1[start] != s2[0]) {
                continue;
            }

            int end = start;  // We already matched s2[0].

            for (int j = 1; j < m; j++) {
                end = nextPos[end + 1][s2[j] - 'a'];
                if (end == n) {
                    break;
                }
            }

            if (end < n && end - start + 1 < bestLength) {
                bestStart = start;
                bestLength = end - start + 1;
            }
        }

        if (bestLength == n + 1) {
            return "";
        }
        return s1.substr(bestStart, bestLength);
    }
};