/* Binary Tree Node Structure
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
};
*/

class Solution {
public:
    vector<int> postOrder(Node *root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }

        stack<Node*> st1, st2;
        st1.push(root);

        while (!st1.empty()) {
            Node* current = st1.top();
            st1.pop();
            st2.push(current);

            if (current->left != nullptr) {
                st1.push(current->left);
            }
            if (current->right != nullptr) {
                st1.push(current->right);
            }
        }

        while (!st2.empty()) {
            result.push_back(st2.top()->data);
            st2.pop();
        }

        return result;
    }
};