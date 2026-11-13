/* Structure of a Binary Search Tree node
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
    vector<int> findCommon(Node* r1, Node* r2) {
        vector<int> result;
        stack<Node*> s1, s2;

        while (true) {
            // Push all left descendants of r1 onto s1
            while (r1 != nullptr) {
                s1.push(r1);
                r1 = r1->left;
            }
            // Push all left descendants of r2 onto s2
            while (r2 != nullptr) {
                s2.push(r2);
                r2 = r2->left;
            }

            // If either stack is empty, no more common nodes can exist
            if (s1.empty() || s2.empty()) {
                break;
            }

            Node* top1 = s1.top();
            Node* top2 = s2.top();

            if (top1->data == top2->data) {
                result.push_back(top1->data);
                s1.pop();
                s2.pop();
                // Move to the right subtrees of both nodes
                r1 = top1->right;
                r2 = top2->right;
            } else if (top1->data < top2->data) {
                // Advance the smaller element in BST 1
                s1.pop();
                r1 = top1->right;
            } else {
                // Advance the smaller element in BST 2
                s2.pop();
                r2 = top2->right;
            }
        }

        return result;
    }
};
