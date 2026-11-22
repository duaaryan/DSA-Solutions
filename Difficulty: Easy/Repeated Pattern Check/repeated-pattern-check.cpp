class Solution {
  public:
    bool findPattern(string& s) {
        int n = s.size();
        int i = 0;

        while (i < n) {
            int countX = 0;
            while (i < n && s[i] == 'x') {
                countX++;
                i++;
            }

            // A valid block must start with at least one 'x'
            if (countX == 0) {
                return false;
            }

            int countY = 0;
            while (i < n && s[i] == 'y') {
                countY++;
                i++;
            }

            // Number of 'y's must match the number of 'x's
            if (countX != countY) {
                return false;
            }
        }

        return true;
    }
};