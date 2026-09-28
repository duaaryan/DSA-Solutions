#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> tree;
    int n;

    // Standard Euclidean algorithm for GCD
    int gcd(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    // Function to build the segment tree
    void build(int node, int start, int end, const vector<int>& arr) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, arr);
        build(2 * node + 1, mid + 1, end, arr);
        tree[node] = gcd(tree[2 * node], tree[2 * node + 1]);
    }

    // Function to handle point updates
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = gcd(tree[2 * node], tree[2 * node + 1]);
    }

    // Function to query range GCD
    int queryGCD(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0; // GCD(x, 0) = x
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        int leftGCD = queryGCD(2 * node, start, mid, l, r);
        int rightGCD = queryGCD(2 * node + 1, mid + 1, end, l, r);
        return gcd(leftGCD, rightGCD);
    }

public:
    vector<int> processQueries(vector<int>& arr, vector<vector<int>>& queries) {
        n = arr.size();
        tree.assign(4 * n, 0);

        // Build the tree with initial array values
        build(1, 0, n - 1, arr);

        vector<int> result;

        // Process each query using proper index tracking
        for (const auto& q : queries) {
            int type = q[0];
            if (type == 0) {
                int l = q[1];
                int r = q[2];
                result.push_back(queryGCD(1, 0, n - 1, l, r));
            } else if (type == 1) {
                int idx = q[1];
                int val = q[2];
                update(1, 0, n - 1, idx, val);
            }
        }

        return result;
    }
};
