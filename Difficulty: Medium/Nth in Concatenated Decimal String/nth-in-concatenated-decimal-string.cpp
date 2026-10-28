class Solution {
public:
    char nthCharacter(int n) {
        long long len = 1;       // Current digit length (1-digit, 2-digit, etc.)
        long long count = 9;     // Count of numbers with the current digit length
        long long start = 1;     // The first number of the current digit length (1, 10, 100...)

        // Step 1: Find the digit length group that contains the nth character
        while (n > len * count) {
            n -= len * count;
            len++;
            count *= 10;
            start *= 10;
        }

        // Step 2: Identify the exact number
        // (n - 1) / len gives the 0-indexed offset from the start number
        long long actualNum = start + (n - 1) / len;

        // Step 3: Find the specific digit inside that number
        string s = to_string(actualNum);
        int digitIndex = (n - 1) % len;

        return s[digitIndex];
    }
};
