/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 
*/

class Solution {
private:
    int min_diff = 1e9; // Initialize with a very large value
    Node* prev = nullptr; // Tracks the previously visited node

    void inorder(Node* root) {
        if (root == nullptr) return;

        // 1. Traverse the left subtree
        inorder(root->left);

        // 2. Process the current node
        if (prev != nullptr) {
            min_diff = std::min(min_diff, std::abs(root->data - prev->data));
        }
        prev = root; // Move prev pointer to the current node

        // 3. Traverse the right subtree
        inorder(root->right);
    }

public:
    int absDiff(Node *root) {
        min_diff = 1e9; // Reset for each test case
        prev = nullptr;

        inorder(root);

        return min_diff;
    }
};
