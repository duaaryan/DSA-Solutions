class Solution {
public:
    int longestKSubstr(string& s, int k) {
        unordered_map<char, int> freq;
        int left = 0;
        int best = -1;
        int n = s.size();

        for (int right = 0; right < n; right++) {
            freq[s[right]]++;

            while (static_cast<int>(freq.size()) > k) {
                char outgoing = s[left];
                freq[outgoing]--;

                if (freq[outgoing] == 0) {
                    freq.erase(outgoing);
                }

                left++;
            }

            if (static_cast<int>(freq.size()) == k) {
                best = max(best, right - left + 1);
            }
        }

        return best;
    }
};