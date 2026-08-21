class Solution {
public:
    int transform(string &s1, string &s2) {
        // Base case: strings of different lengths cannot be transformed
        if (s1.length() != s2.length()) {
            return -1;
        }

        // Check if both strings have the exact same character frequencies
        int count[256] = {0};
        for (int i = 0; i < s1.length(); i++) {
            count[s1[i]]++;
            count[s2[i]]--;
        }

        for (int i = 0; i < 256; i++) {
            if (count[i] != 0) {
                return -1;
            }
        }

        // Greedily match characters from right to left
        int i = s1.length() - 1;
        int j = s2.length() - 1;
        int operations = 0;

        while (i >= 0) {
            if (s1[i] == s2[j]) {
                j--; // Character matches, move both pointers
            } else {
                operations++; // Character doesn't match, it must be moved to the front
            }
            i--;
        }

        return operations;
    }
};
