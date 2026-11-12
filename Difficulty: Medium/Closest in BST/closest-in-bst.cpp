/* Structure of a Binary Search Tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    int minDiff(Node *root, int k) {
        int ans = INT_MAX;

        while (root != nullptr) {
            // Update the minimum absolute difference found so far
            ans = min(ans, abs(root->data - k));

            // Exact match gives the smallest possible difference of 0
            if (ans == 0) {
                return 0;
            }

            // Move left or right based on BST property
            if (k < root->data) {
                root = root->left;
            } else {
                root = root->right;
            }
        }

        return ans;
    }
};
