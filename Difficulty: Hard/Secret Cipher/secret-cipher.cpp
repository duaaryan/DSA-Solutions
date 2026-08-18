#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
private:
    // Function to compute the Z-array for the string
    std::vector<int> computeZ(const std::string& s) {
        int n = s.length();
        std::vector<int> z(n, 0);
        int l = 0, r = 0;

        for (int i = 1; i < n; i++) {
            if (i <= r) {
                z[i] = std::min(r - i + 1, z[i - l]);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }

public:
    std::string compress(std::string s) {
        int n = s.length();
        std::vector<int> z = computeZ(s);
        std::string res = "";

        int i = n - 1;
        while (i >= 0) {
            int len = i + 1;
            // Check if length is even and can be compressed using the Z-array
            if (len % 2 == 0 && z[len / 2] >= len / 2) {
                res += '*';
                i = (len / 2) - 1; // Jump to the end of the first half
            } else {
                res += s[i];
                i--;
            }
        }

        // Since we processed from right to left, reverse the result string
        std::reverse(res.begin(), res.end());
        return res;
    }
};
