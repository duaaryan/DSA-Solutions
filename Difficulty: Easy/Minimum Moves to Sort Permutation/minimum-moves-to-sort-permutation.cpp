class Solution {
public:
    int minMoves(vector<int>& arr) {
        int n = arr.size();

        // Map to store the length of the consecutive increasing chain ending at a number
        unordered_map<int, int> chainLength;
        int maxChain = 0;

        for (int i = 0; i < n; i++) {
            int currentNum = arr[i];

            // If the previous sequential number exists, extend its chain
            if (chainLength.find(currentNum - 1) != chainLength.end()) {
                chainLength[currentNum] = chainLength[currentNum - 1] + 1;
            } else {
                // Otherwise, start a new chain of length 1
                chainLength[currentNum] = 1;
            }

            // Update the maximum chain length found so far
            maxChain = max(maxChain, chainLength[currentNum]);
        }

        // Total moves needed is the size minus the elements already in sequence
        return n - maxChain;
    }
};
