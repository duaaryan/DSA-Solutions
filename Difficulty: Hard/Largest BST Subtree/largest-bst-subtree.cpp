/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  
  struct info{
      int mn,mx,best;
  };
  info solve(Node* root){
      if (root==nullptr){
          return{INT_MAX,INT_MIN,0};
          
      }
      info l = solve(root->left);
      info r = solve(root->right);
      if (l.mx < root->data && root->data < r.mn) {
               return {
                   min(root->data, l.mn),
                   max(root->data, r.mx),
                   l.best + r.best + 1
               };
      } 
      return {INT_MIN, INT_MAX, max(l.best, r.best)};
               
  }
  public:
    int largestBst(Node *root) {
       return solve(root).best;
        
    }
};