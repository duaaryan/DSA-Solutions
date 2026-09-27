/* Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
public:
    void findPaths(Node* root, vector<int>& current, vector<vector<int>>& result) {
        if (root == nullptr) {
            return;
        }

        current.push_back(root->data);   // is node ko current path mein daalo

        if (root->left == nullptr && root->right == nullptr) {
            // yeh leaf hai — poora path save kar do
            result.push_back(current);
        } else {
            findPaths(root->left, current, result);    // pehle left explore karo
            findPaths(root->right, current, result);   // phir right
        }

        current.pop_back();   // backtrack — is node ko path se hatao, taki sibling branch clean rahe
    }

    vector<vector<int>> paths(Node* root) {
        vector<vector<int>> result;
        vector<int> current;
        findPaths(root, current, result);
        return result;
    }
};