class Solution {
  public:
    int firstElementKTime(vector<int>& arr, int k) {
        // Hash map to store the frequency of each element
        unordered_map<int, int> frequencyMap;

        // Traverse the array from left to right
        for (int num : arr) {
            frequencyMap[num]++;

            // As soon as an element hits k occurrences, return it
            if (frequencyMap[num] == k) {
                return num;
            }
        }

        // If no element occurs at least k times
        return -1;
    }
};
