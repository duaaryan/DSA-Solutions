class Solution {
    void solve(int start, int remaining, vector<int>& arr, vector<int>& cur, vector<vector<int>>& res) {
        if (remaining == 0) {
            res.push_back(cur);
            return;
        }
        for (int j = start; j < arr.size(); j++) {
            if (j >start  && arr[j] == arr[j - 1]) continue;   // BLANK 1
            if (arr[j] > remaining) break;                    // sorted hai, aage sab bade

            cur.push_back(arr[j]);
            solve(j+1, remaining - arr[j], arr, cur, res);   // BLANK 2
            cur.pop_back();
        }
    }

public:
    vector<vector<int>> uniqueCombinations(vector<int> &arr, int target) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        vector<int> cur;
        solve(0, target, arr, cur, res);
        return res;
    }
};