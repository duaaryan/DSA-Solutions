class Solution {
public:
    int maxValue(int n) {
        int res = n;
        // Process bits from most significant to least significant
        for (int i = 30; i >= 2; i--) {
            // Check if the i-th, (i-1)-th, and (i-2)-th bits are all set (1)
            if ((res & (1 << i)) && (res & (1 << (i - 1))) && (res & (1 << (i - 2)))) {
                // Clear the (i-2)-th bit (the lowest of the three)
                res &= ~(1 << (i - 2));
            }
        }
        return res;
    }
};
