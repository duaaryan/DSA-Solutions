/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
}; */

class Solution {
public:
    Node* build(vector<int>& postorder, int& postIndex, int inStart, int inEnd,
                unordered_map<int,int>& inorderIndex) {

        if (inStart > inEnd) return nullptr;

        int rootVal = postorder[postIndex--];   // AAKHIR se uthao, piche jaate hue
        Node* root = new Node(rootVal);

        if (inStart == inEnd) return root;

        int inRootIndex = inorderIndex[rootVal];

        // RIGHT pehle banao, LEFT baad mein (order ulta)
        root->right = build(postorder, postIndex, inRootIndex + 1, inEnd, inorderIndex);
        root->left = build(postorder, postIndex, inStart, inRootIndex - 1, inorderIndex);

        return root;
    }

    Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderIndex;
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }

        int postIndex = postorder.size() - 1;   // AAKHIR se shuru karo
        return build(postorder, postIndex, 0, inorder.size() - 1, inorderIndex);
    }
};