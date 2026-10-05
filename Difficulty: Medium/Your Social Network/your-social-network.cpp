#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> socialNetwork(std::vector<int>& arr) {
        std::vector<std::vector<int>> result;
        int n = arr.size() + 1; // n users (numbered 1 to n)

        for (int i = 2; i <= n; ++i) {
            std::vector<std::vector<int>> temp;
            int current = i;
            int steps = 0;

            // Trace path from i upwards to user 1
            while (current >= 2) {
                // arr is 0-indexed: friend of 'current' is at index (current - 2)
                int friendUser = arr[current - 2]; 
                steps++;

                // Save [i, friendUser, steps]
                temp.push_back({i, friendUser, steps});

                // Move up the chain
                current = friendUser;
            }

            // Reverse temp so that users j are sorted in increasing order
            std::reverse(temp.begin(), temp.end());

            // Append to the main result array
            for (const auto& relation : temp) {
                result.push_back(relation);
            }
        }

        return result;
    }
};
