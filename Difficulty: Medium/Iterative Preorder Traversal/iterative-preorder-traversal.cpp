/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
public:
    vector<int> preOrder(Node *root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }

        stack<Node*> st;
        st.push(root);

        while (!st.empty()) {
            Node* current = st.top();
            st.pop();
            result.push_back(current->data);

            if (current->right != nullptr) {
                st.push(current->right);
            }
            if (current->left != nullptr) {
                st.push(current->left);
            }
        }

        return result;
    }
};