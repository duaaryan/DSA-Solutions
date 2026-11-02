class Solution {
    void solve(int start, vector<int>& arr, vector<int>& cur, vector<vector<int>>& res) {
        res.push_back(cur);                    // har node pe save

        for (int j = start; j < arr.size(); j++) {
            if (j > start && arr[j] == arr[j - 1]) continue;
cur.push_back(arr[j]);
            solve(j+1, arr, cur, res);        // BLANK
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> findSubsets(vector<int>& arr) {
        vector<vector<int>> res;
        vector<int> cur;
        sort(arr.begin(), arr.end());
        solve(0, arr, cur, res);
        return res;
    }
};