class Solution {
  public:
   int countNodes(Node* root) {
       if (root == nullptr) return 0;
       return 1 + countNodes(root->left) + countNodes(root->right);
   }
};