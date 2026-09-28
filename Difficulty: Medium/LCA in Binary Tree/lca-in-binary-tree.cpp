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
    Node* lca(Node* root, int n1, int n2) {
        if(root==nullptr || root->data== n1 || root->data== n2){
            return root;
            
        }
        Node* left = lca(root->left,n1,n2);
         Node* right = lca(root->right,n1,n2);
         if (left ==nullptr){
             return right;
             
         }
         if(right == nullptr){
             return left;
         }
         else {
             return root;
         }
    }
};