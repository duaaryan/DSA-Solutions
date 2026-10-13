/* Structure of a Tree Node
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
  Node* insert(Node* root, int key){
      if(root==nullptr) return new Node(key);
      if(key <root->data) root->left = insert(root->left, key);
      else root->right = insert(root->right, key);
      return root;
  }
    Node* preToBST(vector<int>& pre) {
    Node* root = nullptr;
    for(int x : pre) root= insert(root, x);
    return root;
        
    }
};