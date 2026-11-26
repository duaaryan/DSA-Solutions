class Solution {
  private:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

  public:
    vector<int> countVowels(string &s, vector<vector<int>> &queries) {
        int n = s.size();
        vector<int> pref(n + 1, 0);

        // Build the prefix sum array
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (isVowel(s[i]) ? 1 : 0);
        }

        vector<int> ans;
        ans.reserve(queries.size());

        // Answer each query in O(1) time
        for (const auto &q : queries) {
            int l = q[0];
            int r = q[1];
            ans.push_back(pref[r + 1] - pref[l]);
        }

        return ans;
    }
};
