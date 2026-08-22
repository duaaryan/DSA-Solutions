

class Solution {
public:
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        // If the starting cell is an obstacle, no cells can be visited
        if (mat[r][c] == '#') {
            return 0;
        }

        // Track the maximum remaining up and down moves for each cell
        // Initialized to -1 to signify unvisited/unreachable states
        vector<vector<int>> max_u(n, vector<int>(m, -1));
        vector<vector<int>> max_d(n, vector<int>(m, -1));

        // Deque elements: {current_row, current_col, remaining_u, remaining_d}
        deque<vector<int>> dq;

        // Initialize start position
        dq.push_back({r, c, u, d});
        max_u[r][c] = u;
        max_d[r][c] = d;

        int count = 0;

        // Direction vectors for standard movements
        // Up, Down, Left, Right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!dq.empty()) {
            auto curr = dq.front();
            dq.pop_front();

            int cr = curr[0];
            int cc = curr[1];
            int cu = curr[2];
            int cd = curr[3];

            // Skip if we found a strictly better path to this cell already
            if (cu < max_u[cr][cc] && cd < max_d[cr][cc]) {
                continue;
            }

            for (int i = 0; i < 4; i++) {
                int nr = cr + dr[i];
                int nc = cc + dc[i];

                // Check grid boundaries and obstacle constraints
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == '.') {
                    int nu = cu;
                    int nd = cd;

                    // Consume an up move if moving up
                    if (i == 0) nu--; 
                    // Consume a down move if moving down
                    if (i == 1) nd--; 

                    // Proceed only if move budgets are valid
                    if (nu >= 0 && nd >= 0) {
                        // Push to front for 0-cost (left/right) or back for 1-cost (up/down)
                        if (nu > max_u[nr][nc] || nd > max_d[nr][nc]) {
                            max_u[nr][nc] = max(max_u[nr][nc], nu);
                            max_d[nr][nc] = max(max_d[nr][nc], nd);

                            if (i == 2 || i == 3) {
                                dq.push_front({nr, nc, nu, nd});
                            } else {
                                dq.push_back({nr, nc, nu, nd});
                            }
                        }
                    }
                }
            }
        }

        // Count all unique cells reached during traversal
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (max_u[i][j] != -1 || max_d[i][j] != -1) {
                    count++;
                }
            }
        }

        return count;
    }
};
