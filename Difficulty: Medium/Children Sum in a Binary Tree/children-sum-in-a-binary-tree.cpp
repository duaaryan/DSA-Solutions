/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
public:
    bool isSumProperty(Node* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return true;   // null ya leaf — automatically valid
        }

        int leftVal = (root->left) ? root->left->data : 0;
        int rightVal = (root->right) ? root->right->data : 0;

        if (root->data != leftVal + rightVal) {
            return false;   // yeh node hi fail ho gaya, poora tree invalid
        }

        // is node ke liye sahi hai, ab bacchon ko bhi check karo
        return isSumProperty(root->left) && isSumProperty(root->right);
    }
};