class Solution {
public:
    vector<int> lexicographicallyLargest(vector<int> &arr) {
        int n = arr.size();
        int i = 0;

        while (i < n) {
            int j = i;
            // Find the boundary of the contiguous same-parity subarray
            while (j < n && (arr[j] % 2 == arr[i] % 2)) {
                j++;
            }
            // Sort this independent segment in descending order
            sort(arr.begin() + i, arr.begin() + j, greater<int>());

            // Move to the start of the next segment
            i = j;
        }

        return arr;
    }
};
