class Solution {
public:
    void mergeTwoParts(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return;

        // Step 1: Find the break point between the two sorted halves
        int pivot = -1;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                pivot = i;
                break;
            }
        }

        // If no pivot is found, the array is already completely sorted
        if (pivot == -1) return;

        // Step 2: In-place Merge using the Gap Method
        int gap = (n + 1) / 2;
        while (gap > 0) {
            int i = 0;
            int j = gap;

            while (j < n) {
                if (arr[i] > arr[i + 1]) { // Re-verify boundaries if needed, but simple swap works
                    if (arr[i] > arr[j]) {
                        swap(arr[i], arr[j]);
                    }
                } else {
                    if (arr[i] > arr[j]) {
                        swap(arr[i], arr[j]);
                    }
                }
                i++;
                j++;
            }

            if (gap == 1) {
                break;
            }
            gap = (gap + 1) / 2;
        }
    }
};
