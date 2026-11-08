class Solution {
public:
    int getCount(string &s, int k) {
        // Frequency array to store the number of groups for each ASCII character
        int group_count[256] = {0};

        if (s.empty()) return 0;

        // The first character always starts the first group
        group_count[(unsigned char)s[0]]++;

        // Traverse the string to find subsequent group boundaries
        for (size_t i = 1; i < s.length(); i++) {
            if (s[i] != s[i-1]) {
                group_count[(unsigned char)s[i]]++;
            }
        }

        // Count how many distinct characters appear in exactly k groups
        int ans = 0;
        for (int i = 0; i < 256; i++) {
            if (group_count[i] == k) {
                ans++;
            }
        }

        return ans;
    }
};
