class Solution {
    void solve(int i, int remaining, vector<int>& arr, vector<int>& cur, vector<vector<int>>& res) {
        if (remaining == 0) {                       // combination ban gayi
            res.push_back(cur);
            return;
        }
        if (i == arr.size() || remaining < 0) return;

        // take: arr[i] le liya, aur usi i pe raho (dobara le sakte ho)
        cur.push_back(arr[i]);
        solve(i, remaining - arr[i], arr, cur, res);
        cur.pop_back();

        // skip: ab arr[i] kabhi nahi lenge, agle element pe jao
        solve(i + 1, remaining, arr, cur, res);
    }

public:
    vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        solve(0, target, arr, cur, res);
        return res;
    }
};