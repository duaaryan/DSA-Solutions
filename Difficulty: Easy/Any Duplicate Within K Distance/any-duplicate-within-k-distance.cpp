class Solution {
public:
    bool checkWithinK(vector<int>& arr, int k) {
        unordered_set<int> window;

        for (int i = 0; i < arr.size(); i++) {
            // If the element is already in the window, a duplicate exists within distance k
            if (window.count(arr[i])) {
                return true;
            }

            // Add the current element to the window
            window.insert(arr[i]);

            // Maintain the window size of at most k elements
            if (window.size() > k) {
                window.erase(arr[i - k]);
            }
        }

        return false;
    }
};
