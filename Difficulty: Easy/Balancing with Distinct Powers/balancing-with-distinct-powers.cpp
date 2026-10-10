class Solution {
public:
    bool balancePan(int a, int b) {
        while (b > 0) {
            int remainder = b % a;

            if (remainder == 0) {
                b /= a;
            } 
            else if (remainder == 1) {
                b = (b - 1) / a;
            } 
            else if (remainder == a - 1) {
                b = (b + 1) / a;
            } 
            else {
                // If any digit requires a coefficient other than 0, 1, or -1
                return false;
            }
        }
        return true;
    }
};
