class Solution {
    string keys[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void solve(int i, string& cur, vector<int>& arr, vector<string>& res) {
       if (i == arr.size()) {
           if (!cur.empty()) res.push_back(cur);   // khaali string save mat karo
           return;
       }

        string letters = keys[arr[i]];  
        
        if (letters.empty()) {                    // digit 0 ya 1: koi letter nahi
            solve(i + 1, cur, arr, res);          // bas agle digit pe chale jao
            return;
        }

        for (char c : letters) {
            cur.push_back(c);
            solve(i + 1, cur, arr, res);          // agle digit pe
            cur.pop_back();                       // wapas hato
        }
    }

public:
    vector<string> possibleWords(vector<int> &arr) {
        vector<string> res;
        string cur = "";
        solve(0, cur, arr, res);
        return res;
    }
};