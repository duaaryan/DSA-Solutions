class Solution {
    void solve(int start, vector<int>& arr, vector<int>& cur, vector<vector<int>>& res) {
        res.push_back(cur);                    // har node pe save

        for (int j = start; j < arr.size(); j++) {
            cur.push_back(arr[j]);
            solve(j+1, arr, cur, res);        // BLANK
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>> res;
        vector<int> cur;
        solve(0, arr, cur, res);
        return res;
    }
};