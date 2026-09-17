/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
public:
    int height(Node* root) {
        if (root == nullptr) return 0;

        int lh = height(root->left);
        if (lh == -1) return -1;

        int rh = height(root->right);
        if (rh == -1) return -1;

        if (abs(lh - rh) > 1) return -1;

        return 1 + max(lh, rh);
    }

    bool isBalanced(Node *root) {
        return height(root) != -1;
    }
};