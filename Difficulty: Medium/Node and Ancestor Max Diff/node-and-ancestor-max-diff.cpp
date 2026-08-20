/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
public:
    int maxDiffUtil(Node* root, int& max_diff) {
        // Base case: return a very large value for null nodes
        if (root == nullptr) {
            return INT_MAX;
        }

        // Leaf nodes have no descendants
        if (root->left == nullptr && root->right == nullptr) {
            return root->data;
        }

        // Find the minimum values in left and right subtrees
        int left_min = maxDiffUtil(root->left, max_diff);
        int right_min = maxDiffUtil(root->right, max_diff);

        // Minimum value among all descendants
        int min_descendant = min(left_min, right_min);

        // Update the maximum difference found so far
        max_diff = max(max_diff, root->data - min_descendant);

        // Return the minimum value including the current node
        return min(root->data, min_descendant);
    }

    int maxDiff(Node* root) {
        int max_diff = INT_MIN;
        maxDiffUtil(root, max_diff);
        return max_diff;
    }
};
