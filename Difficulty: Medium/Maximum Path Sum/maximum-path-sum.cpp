/* Structure of binary tree node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int findMaxSum(Node *root) {
        int maxi = INT_MIN;
        path(root, maxi);
        return maxi;
    }
    public:
    int path(Node* root, int& maxi){
        if(root==nullptr) return 0;
        int left = max(0, path(root->left, maxi));
        int right = max(0, path(root->right, maxi));
        maxi = max(maxi, left + right + root->data);
        
    return max(left, right) + root->data;
        
    }
};