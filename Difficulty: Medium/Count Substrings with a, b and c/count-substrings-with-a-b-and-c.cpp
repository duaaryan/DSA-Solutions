class Solution {
public:
    int countSubstring(string &s) {
        int last[3] = {-1, -1, -1};   // a, b, c ki aakhri position
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;                       // is letter ki last position update
            count += 1 + min({last[0], last[1], last[2]});
        }
        return count;
    }
};