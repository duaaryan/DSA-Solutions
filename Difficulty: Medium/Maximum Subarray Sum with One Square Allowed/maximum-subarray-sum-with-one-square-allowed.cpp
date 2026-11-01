class Solution {
public:
    int maximumSubarray(std::vector<int>& arr) {
        if (arr.empty()) return 0;

        // Convert to long long to prevent integer overflow during squaring (10^3 * 10^3 = 10^6, but intermediate additions can accumulate)
        long long max_no_square = arr[0];
        long long max_one_square = (long long)arr[0] * arr[0];
        long long overall_max = std::max(max_no_square, max_one_square);

        for (size_t i = 1; i < arr.size(); ++i) {
            long long x = arr[i];
            long long x_sq = x * x;

            // Calculate choices for max_one_square ending at index i
            long long choice1 = x_sq;
            long long choice2 = max_one_square + x;
            long long choice3 = max_no_square + x_sq;

            max_one_square = std::max({choice1, choice2, choice3});

            // Calculate choices for max_no_square ending at index i
            max_no_square = std::max(x, max_no_square + x);

            // Update the global maximum encountered so far
            overall_max = std::max({overall_max, max_no_square, max_one_square});
        }

        return static_cast<int>(overall_max);
    }
};
