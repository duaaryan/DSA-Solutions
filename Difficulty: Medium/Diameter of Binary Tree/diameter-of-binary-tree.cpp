/* Structure of binary tree Node 
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
    int diameter(Node* root) {
       int dia =0;
       height(root, dia);
       return dia;
    }
    
    public:
    int height(Node* root, int& dia){
        if(root== nullptr) return 0;
         int lh = height(root->left, dia);
         int rh = height(root->right, dia);
         dia= max(dia,lh+rh);
         return 1+max(lh,rh);
    }
};