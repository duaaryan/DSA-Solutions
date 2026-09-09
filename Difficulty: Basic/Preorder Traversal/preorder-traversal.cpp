/* Structure of Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
public:
    vector<int> preOrder(Node* root) {
        vector<int> result;
        preOrderHelper(root, result);
        return result;
    }

    void preOrderHelper(Node* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        result.push_back(root->data);
        preOrderHelper(root->left, result);
        preOrderHelper(root->right, result);
    }
};