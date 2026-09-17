/* Tree Node Structure 
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
  public:
    int maxDepth(Node *root) {
        if(root == nullptr) return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        
        return 1+max(lh,rh);
        
    }
};
