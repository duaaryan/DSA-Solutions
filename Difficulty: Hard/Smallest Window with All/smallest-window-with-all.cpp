class Solution {
public:
    string minWindow(string& s, string& p) {
        vector<int> need(26, 0);
        vector<int> have(26, 0);

        for (char ch : p) {
            need[ch - 'a']++;
        }

        int missing = p.size();
        int left = 0;
        int bestStart = 0;
        int n = s.size();
        int bestLength = n + 1;

        for (int right = 0; right < n; right++) {
            int incoming = s[right] - 'a';
            have[incoming]++;

            if (have[incoming] <= need[incoming]) {
                missing--;
            }

            while (missing == 0) {
                int length = right - left + 1;
                if (length < bestLength) {
                    bestLength = length;
                    bestStart = left;
                }

                int outgoing = s[left] - 'a';
                have[outgoing]--;
                if (have[outgoing] < need[outgoing]) {
                    missing++;
                }
                left++;
            }
        }

        if (bestLength == n + 1) {
            return "";
        }
        return s.substr(bestStart, bestLength);
    }
};