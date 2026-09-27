class Solution {
public:
    vector<vector<int>> adj;
    string s;
    int ans;
    vector<int> R, B, F, G;
    // R[u]: longest downward all-RED chain starting at u
    // B[u]: longest downward all-BLUE chain starting at u
    // F[u]: longest downward valid chain (R*B* pattern) starting at u
    // G[u]: longest downward "reverse" chain (B*R* pattern) starting at u

    void dfs(int u, int parent) {
        char cu = s[u - 1];
        int extR = 0, extB = 0, extFraw = 0, extGraw = 0;
        int bestF1 = 0, bestF1i = -1, bestF2 = 0;
        int bestG1 = 0, bestG1i = -1, bestG2 = 0;

        for (int c : adj[u]) {
            if (c == parent) continue;
            dfs(c, u);

            if (cu == 'R') extR = max(extR, R[c]);
            if (cu == 'B') extB = max(extB, B[c]);

            int fraw = (cu == 'R') ? F[c] : B[c];
            extFraw = max(extFraw, fraw);
            int childF = 1 + fraw;
            if (childF > bestF1) { bestF2 = bestF1; bestF1 = childF; bestF1i = c; }
            else if (childF > bestF2) { bestF2 = childF; }

            int graw = (cu == 'B') ? G[c] : R[c];
            extGraw = max(extGraw, graw);
            int childG = 1 + graw;
            if (childG > bestG1) { bestG2 = bestG1; bestG1 = childG; bestG1i = c; }
            else if (childG > bestG2) { bestG2 = childG; }
        }

        R[u] = (cu == 'R') ? 1 + extR : 0;
        B[u] = (cu == 'B') ? 1 + extB : 0;
        F[u] = 1 + extFraw;
        G[u] = 1 + extGraw;

        int localBest = max(F[u], G[u]);

        // combine two DIFFERENT children: one supplies the "reverse" side,
        // one supplies the "forward" side, meeting at u
        if (bestF1i != -1 && bestG1i != -1) {
            int bend;
            if (bestF1i != bestG1i) {
                bend = bestF1 + bestG1 - 1;   // -1: u counted in both, don't double count
            } else {
                int opt1 = (bestF2 > 0) ? bestF2 + bestG1 - 1 : -1;
                int opt2 = (bestG2 > 0) ? bestF1 + bestG2 - 1 : -1;
                bend = max(opt1, opt2);
            }
            localBest = max(localBest, bend);
        }

        ans = max(ans, localBest);
    }

    int longestPath(string &s, vector<vector<int>>& edges) {
        int n = s.size();
        this->s = s;
        adj.assign(n + 1, {});
        R.assign(n + 1, 0); B.assign(n + 1, 0); F.assign(n + 1, 0); G.assign(n + 1, 0);
        ans = 1;

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(1, 0);
        return ans;
    }
};