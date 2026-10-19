class Solution {
private:
    int dfs(int i, vector<int>& arr, vector<int>& state) {
        // Base Case: If the jump takes us outside the array boundaries, it safely escapes!
        if (i < 0 || i >= arr.size()) {
            return 2; // Good state
        }

        // If we hit an index that is already fully computed, return its cached state
        if (state[i] == 2 || state[i] == 3) {
            return state[i];
        }

        // If we encounter an index currently in the recursion stack, a cycle is detected
        if (state[i] == 1) {
            return 3; // Bad state
        }

        // Mark the current index as "Visiting"
        state[i] = 1;

        // Calculate the next index position
        int next_idx = i + arr[i];

        // Recursively find the state of the next position
        state[i] = dfs(next_idx, arr, state);

        return state[i];
    }

public:
    int goodIndices(vector<int>& arr) {
        int n = arr.size();
        // state array tracks: 0 = unvisited, 1 = visiting, 2 = good, 3 = bad
        vector<int> state(n, 0); 
        int good_count = 0;

        // Run DFS from every unvisited index
        for (int i = 0; i < n; i++) {
            if (state[i] == 0) {
                dfs(i, arr, state);
            }
        }

        // Count how many indices resulted in a "Good" (2) state
        for (int i = 0; i < n; i++) {
            if (state[i] == 2) {
                good_count++;
            }
        }

        return good_count;
    }
};
