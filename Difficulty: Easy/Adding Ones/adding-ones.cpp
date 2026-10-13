class Solution {
   public:
     vector<int> update(int n, vector<int>& updates) {
         vector<int> arr(n, 0);

         // Step 1: Mark the starting index for each update
         for (int i = 0; i < updates.size(); i++) {
             int idx = updates[i] - 1; // Convert 1-based to 0-based indexing
             if (idx < n) {
                 arr[idx]++;
             }
         }

         // Step 2: Compute the prefix sum to propagate the updates
         for (int i = 1; i < n; i++) {
             arr[i] += arr[i - 1];
         }

         return arr;
     }
 };
