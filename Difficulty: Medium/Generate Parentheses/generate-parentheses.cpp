class Solution {
    void solve(int open, int close, int pairs, string& cur, vector<string>& res) {
        // string poori ban gayi (n = 2 * pairs characters)
        if (cur.size() == 2 * pairs) {
            res.push_back(cur);
            return;
        }

        // '(' laga sakte ho agar abhi pairs ki limit nahi aayi
        if (open < pairs) {
            cur.push_back('(');
            solve(open + 1, close, pairs, cur, res);
            cur.pop_back();       // wapas hato, doosra raasta try karne ke liye
        }

        // ')' laga sakte ho agar koi '(' abhi band nahi hua
        if (close < open) {
            cur.push_back(')');
            solve(open, close + 1, pairs, cur, res);
            cur.pop_back();
        }
    }

public:
    vector<string> generateParentheses(int n) {
        vector<string> res;
        string cur = "";
        solve(0, 0, n / 2, cur, res);    // n total length hai, toh pairs = n / 2
        return res;
    }
};