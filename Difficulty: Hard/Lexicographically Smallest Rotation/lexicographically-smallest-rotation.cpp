class Solution {
public:
    string lexiString(string &s) {
        int n = s.length();
        // Concatenate the string with itself to handle cyclic rotations
        string ds = s + s;

        // Failure function array initialized to -1
        vector<int> f(2 * n, -1);
        int least = 0; // Stores the starting index of the lexicographically smallest rotation

        for (int j = 1; j < 2 * n; ++j) {
            int i = f[j - least - 1];

            while (i != -1 && ds[j] != ds[least + i + 1]) {
                if (ds[j] < ds[least + i + 1]) {
                    least = j - i - 1;
                }
                i = f[i];
            }

            if (ds[j] != ds[least + i + 1]) {
                if (ds[j] < ds[least]) {
                    least = j;
                }
                f[j - least] = -1;
            } else {
                f[j - least] = i + 1;
            }
        }

        // Return the best rotation of length n
        return ds.substr(least, n);
    }
};
