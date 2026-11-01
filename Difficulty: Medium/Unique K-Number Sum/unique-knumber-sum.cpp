class Solution {
    void solve(int num, int remaining, int k, vector<int>& cur, vector<vector<int>>& res) {
        if (cur.size() == k) {
            if (remaining == 0) res.push_back(cur);
            return;
        }
        if (num > 9 || remaining < 0) return;

        // take
        cur.push_back(num);
        solve(num+1, remaining - num, k, cur, res);    // BLANK 1
        cur.pop_back();

        // skip
        solve(num +1, remaining, k, cur, res);           // BLANK 2
    }

public:
    vector<vector<int>> combinationSum(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        solve(1, n, k, cur, res);
        return res;
    }
};