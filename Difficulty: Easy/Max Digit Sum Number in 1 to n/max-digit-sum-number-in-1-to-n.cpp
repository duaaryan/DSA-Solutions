class Solution {
public:
    // Helper function to calculate the sum of digits
    int getDigitSum(long long num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int findMax(int n) {
        string s = to_string(n);
        long long maxNum = n;
        int maxSum = getDigitSum(n);

        // Iterate through each digit from left to right
        for (int i = 0; i < s.length(); i++) {
            // If the digit is '0', we can't decrement it safely without affecting length/value unpredictably
            if (s[i] == '0') continue;

            string candidateStr = s;
            // Decrement the current digit
            candidateStr[i]--; 

            // Set all trailing digits to '9'
            for (int j = i + 1; j < candidateStr.length(); j++) {
                candidateStr[j] = '9';
            }

            long long candidate = stoll(candidateStr);
            int candidateSum = getDigitSum(candidate);

            // Update if we find a strictly greater sum, 
            // or equal sum with a larger integer value
            if (candidateSum > maxSum) {
                maxSum = candidateSum;
                maxNum = candidate;
            } else if (candidateSum == maxSum) {
                maxNum = max(maxNum, candidate);
            }
        }

        return maxNum;
    }
};
