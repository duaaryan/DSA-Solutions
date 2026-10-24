class Solution {
public:
    bool isPossible(int n, int m, string& s) {
        // Current relative coordinates from an imaginary starting cell (0,0)
        int r = 0, c = 0;

        // Track the extreme boundaries reached during the path
        int min_r = 0, max_r = 0;
        int min_c = 0, max_c = 0;

        for (char ch : s) {
            if (ch == 'L') {
                c--;
            } else if (ch == 'R') {
                c++;
            } else if (ch == 'U') {
                r--;
            } else if (ch == 'D') {
                r++;
            }

            // Update extreme boundaries
            min_r = min(min_r, r);
            max_r = max(max_r, r);
            min_c = min(min_c, c);
            max_c = max(max_c, c);
        }

        // Calculate total vertical and horizontal spans of the path footprint
        int height_span = max_r - min_r + 1;
        int width_span = max_c - min_c + 1;

        // If the path footprint fits within the grid dimensions, return true
        return (height_span <= n && width_span <= m);
    }
};
