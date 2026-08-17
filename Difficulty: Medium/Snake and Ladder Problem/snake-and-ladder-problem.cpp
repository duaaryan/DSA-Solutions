class Solution {
public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        int target = n * n;

        // Step 1: Create a board array initialized to its own index
        vector<int> board(target + 1, -1);

        // Populate ladders
        for (int i = 0; i < lad.size(); i += 2) {
            board[lad[i]] = lad[i + 1];
        }

        // Populate snakes
        for (int i = 0; i < sn.size(); i += 2) {
            board[sn[i]] = sn[i + 1];
        }

        // Step 2: BFS Initialization
        vector<bool> visited(target + 1, false);
        queue<pair<int, int>> q; // stores {current_cell, distance/throws}

        q.push({1, 0});
        visited[1] = true;

        // Step 3: Standard BFS loop
        while (!q.empty()) {
            auto [curr, dist] = q.front();
            q.pop();

            // If target cell reached
            if (curr == target) {
                return dist;
            }

            // Try all 6 dice rolls
            for (int dice = 1; dice <= 6; ++dice) {
                int next_cell = curr + dice;

                if (next_cell <= target) {
                    // Check if there is a snake or ladder
                    if (board[next_cell] != -1) {
                        next_cell = board[next_cell];
                    }

                    // If not visited, add to queue
                    if (!visited[next_cell]) {
                        visited[next_cell] = true;
                        q.push({next_cell, dist + 1});
                    }
                }
            }
        }

        return -1; // If target is unreachable
    }
};
