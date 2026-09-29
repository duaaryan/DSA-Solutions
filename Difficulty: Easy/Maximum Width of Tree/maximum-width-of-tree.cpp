/*  Structure of a Binary Tree
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
    int maxWidth(Node* root) {
        if (!root) return 0;

        int ans = 0;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            ans = max(ans, size);   // this level's actual node count

            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return ans;
    }
};