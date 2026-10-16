class Solution {
public:
    int countAlwaysFound(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return 1;

        vector<int> max_left(n);
        vector<int> min_right(n);

        // Fill max_left: max_left[i] maintains the max element from 0 to i-1
        max_left[0] = INT_MIN; 
        for (int i = 1; i < n; i++) {
            max_left[i] = max(max_left[i - 1], arr[i - 1]);
        }

        // Fill min_right: min_right[i] maintains the min element from i+1 to n-1
        min_right[n - 1] = INT_MAX;
        for (int i = n - 2; i >= 0; i--) {
            min_right[i] = min(min_right[i + 1], arr[i + 1]);
        }

        // Count elements that satisfy the condition
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > max_left[i] && arr[i] < min_right[i]) {
                count++;
            }
        }

        return count;
    }
};
