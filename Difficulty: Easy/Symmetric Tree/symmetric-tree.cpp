/* Structure of binary tree node
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/


class Solution {
public:
    bool isMirror(Node* left, Node* right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr) return false;

        return (left->data == right->data)
            && isMirror(left->left, right->right)   // outer pair
            && isMirror(left->right, right->left);  // inner pair
    }

    bool isSymmetric(Node* root) {
        if (root == nullptr) return true;
        return isMirror(root->left, root->right);
    }
};