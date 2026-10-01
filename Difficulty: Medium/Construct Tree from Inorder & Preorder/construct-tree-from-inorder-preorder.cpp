/* Structure of a Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
public:
    Node* build(vector<int>& preorder, int& preIndex, int inStart, int inEnd, unordered_map<int,int>& inorderIndex) {
        if (inStart > inEnd) return nullptr;

        int rootVal = preorder[preIndex++];
        Node* root = new Node(rootVal);

        if (inStart == inEnd) return root;

        int inRootIndex = inorderIndex[rootVal];
        root->left = build(preorder, preIndex, inStart, inRootIndex - 1, inorderIndex);
        root->right = build(preorder, preIndex, inRootIndex + 1, inEnd, inorderIndex);

        return root;
    }

   Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        unordered_map<int, int> inorderIndex;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        int preIndex = 0;
        return build(preorder, preIndex, 0, inorder.size() - 1, inorderIndex);
    }
};