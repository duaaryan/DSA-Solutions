class Solution {
public:
    int beautySum(string &s) {
        int n = s.length();
        int total_beauty = 0;

        // Outer loop: Sets the starting boundary of the substring
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0); // Reset frequencies for every new starting position

            // Inner loop: Dynamically extends the substring window
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++; // Map character to index 0-25 and increment

                int max_freq = 0;
                int min_freq = n; // Initialize with a large number

                // Find Max and Min among active frequencies
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        max_freq = max(max_freq, freq[k]);
                        min_freq = min(min_freq, freq[k]);
                    }
                }

                // Add the beauty of the current substring to the total
                total_beauty += (max_freq - min_freq);
            }
        }

        return total_beauty;
    }
};