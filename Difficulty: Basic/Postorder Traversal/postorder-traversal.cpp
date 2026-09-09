/* Structure of Binary Tree Node
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
    vector<int> postOrder(Node* root) {
        vector<int> result;
        postorderhelper(root, result);
        return result;
    }
    void postorderhelper(Node* root, vector<int>& result){
    if(root==nullptr) return;
     postorderhelper(root->left, result);
     postorderhelper(root->right, result);
     result.push_back(root->data);
    }
};