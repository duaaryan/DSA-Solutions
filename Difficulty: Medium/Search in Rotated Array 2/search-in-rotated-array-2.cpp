class Solution {
public:
    bool search(vector<int>& arr, int key) {
        int low = 0;
        int high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == key) {
                return true;
            }

            // Edge case: duplicates handle
            if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
                low++;
                high--;
                continue;
            }

            // Check if left half is sorted
            if (arr[low] <= arr[mid]) {
                // Check if key exists in the left sorted half
                if (arr[low] <= key && key < arr[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } 
            // Otherwise, right half must be sorted
            else {
                // Check if key exists in the right sorted half
                if (arr[mid] < key && key <= arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};
