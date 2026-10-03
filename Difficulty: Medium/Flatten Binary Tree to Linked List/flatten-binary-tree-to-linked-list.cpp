/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  Node* prev = nullptr;
  
    void flatten(Node* root) {
        if(root==nullptr) return;
         
         flatten(root->right);
         flatten(root->left);
         
         root->right=prev;
         root->left=nullptr;
          
          
          
          prev = root;
        
        
    }
};