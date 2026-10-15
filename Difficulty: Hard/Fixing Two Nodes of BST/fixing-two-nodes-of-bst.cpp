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
}; */

class Solution {
    Node *first, *middle, *last, *prev;

    void inorder(Node* root) {
        if (root == nullptr) return;

        inorder(root->left);

        // Detect violation
        if (prev != nullptr && root->data < prev->data) {
            // If this is the first violation, set first and middle
            if (first == nullptr) {
                first = prev;
                middle = root;
            } 
            // If this is the second violation, set last
            else {
                last = root;
            }
        }

        // Move prev pointer forward
        prev = root;

        inorder(root->right);
    }

public:
    Node* correctBST(Node* root) {
        // Initialize/Reset all pointers explicitly for every test case
        first = middle = last = prev = nullptr;

        // Run the inorder traversal to find the misplaced nodes
        inorder(root);

        // Fix the tree by swapping the values
        if (first != nullptr && last != nullptr) {
            swap(first->data, last->data);
        } else if (first != nullptr && middle != nullptr) {
            swap(first->data, middle->data);
        }

        return root;
    }
};
