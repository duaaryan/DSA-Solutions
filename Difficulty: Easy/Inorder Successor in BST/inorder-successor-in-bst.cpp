/*
Definition for Node
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
    int inOrderSuccessor(Node *root, Node *k) {
        Node* successor = nullptr;
        while (root != nullptr){
            if (root->data <= k->data){
                root = root->right;
            }
            else {
                successor = root;
                root= root->left;
            }
        }
        return (successor != nullptr) ? successor->data : -1;
    }
};