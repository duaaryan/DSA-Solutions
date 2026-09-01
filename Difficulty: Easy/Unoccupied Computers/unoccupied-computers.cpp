class Solution {
public:
    int solve(int n, string s) {
        // Track customer status: 0 = not seen, 1 = occupying computer, 2 = turned away
        vector<int> status(26, 0); 
        int turnedAwayCount = 0;
        int occupiedComputers = 0;

        for (char ch : s) {
            int idx = ch - 'A';

            if (status[idx] == 0) { // First occurrence (Arrival)
                if (occupiedComputers < n) {
                    status[idx] = 1; // Customer gets a computer
                    occupiedComputers++;
                } else {
                    status[idx] = 2; // Customer is turned away
                    turnedAwayCount++;
                }
            } else { // Second occurrence (Departure)
                if (status[idx] == 1) {
                    occupiedComputers--; // Free up the computer
                }
                // If status[idx] was 2, they just leave without affecting computers
            }
        }

        return turnedAwayCount;
    }
};