class Solution {
public:
    string findRollOut(string& s, vector<int>& roll) {
        int n = s.length();
        // Array to store how many times each position serves as an end-boundary for a roll
        vector<int> rollCount(n, 0);

        // Step 1: Mark the end boundaries of each roll operation
        for (int x : roll) {
            if (x > 0) {
                // Since roll values are 1-indexed lengths, 
                // the last affected index is min(x - 1, n - 1) to avoid out-of-bounds
                rollCount[min(x - 1, n - 1)]++;
            }
        }

        // Step 2: Accumulate rolls from right to left
        int currentRolls = 0;
        for (int i = n - 1; i >= 0; i--) {
            currentRolls += rollCount[i];

            // Step 3: Shift the character and handle the 'z' to 'a' wrap-around
            int shift = currentRolls % 26;
            int newChar = s[i] - 'a' + shift;
            s[i] = 'a' + (newChar % 26);
        }

        return s;
    }
};
