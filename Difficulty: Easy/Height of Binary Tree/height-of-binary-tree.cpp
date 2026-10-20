/* Structrue of Binary Tree Node
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
       if(root==nullptr) return -1;
       
       int lh = height(root->left);
       int rh = height(root->right);
         return 1+max(lh,rh);
    }
};