/* Binary Tree Node Structure
class Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
public:
    void inorder(Node* root, vector<int>& v) {
        if (root == nullptr) return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }

    bool findTarget(Node* root, int target) {
        vector<int> v;
        inorder(root, v);

        int i = 0, j = v.size() - 1;
        while (i < j) {
            int sum = v[i] + v[j];
            if (sum == target) return true;
            else if (sum < target) i++;
            else j--;
        }
        return false;
    }
};