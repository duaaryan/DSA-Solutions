#include <vector>
#include <queue>

class Solution {
public:
    int minComputation(std::vector<int>& files) {
        // Create a min-heap (priority queue with greater comparator)
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        // Push all file sizes into the min-heap
        for (int size : files) {
            minHeap.push(size);
        }

        int totalCost = 0;

        // Combine files until only one remains
        while (minHeap.size() > 1) {
            // Extract the two smallest files
            int first = minHeap.top();
            minHeap.pop();

            int second = minHeap.top();
            minHeap.pop();

            // The cost to merge them
            int currentMergeCost = first + second;
            totalCost += currentMergeCost;

            // Push the merged file back into the heap
            minHeap.push(currentMergeCost);
        }

        return totalCost;
    }
};
