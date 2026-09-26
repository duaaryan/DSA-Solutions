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
    vector<int> leftView(Node *root) {
         
                vector<int> ans;
                if (root == nullptr) return ans;

                queue<Node*> q;
                q.push(root);

                while (!q.empty()) {
                    int levelSize = q.size();

                    for (int i = 0; i < levelSize; i++) {
                        Node* node = q.front();
                        q.pop();

                        if (i == 0) {       
                            ans.push_back(node->data);
                        }

                        if (node->left != nullptr) q.push(node->left);
                        if (node->right != nullptr) q.push(node->right);
                    }
                }

                return ans;
            }
        };