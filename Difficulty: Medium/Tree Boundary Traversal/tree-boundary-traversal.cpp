/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */


 class Solution {
 public:
     bool isLeaf(Node* node) {
         return node->left == nullptr && node->right == nullptr;
     }

     // Collects nodes from root down to (but not including) the leftmost leaf,
     // skipping leaves themselves — added top-down.
     void addLeftBoundary(Node* root, vector<int>& boundary) {
         Node* current = root->left;
         while (current != nullptr) {
             if (!isLeaf(current)) {
                 boundary.push_back(current->data);
             }
             if (current->left != nullptr) {
                 current = current->left;
             } else {
                 current = current->right;
             }
         }
     }

     // Collects all leaf nodes from left to right.
     void addLeaves(Node* node, vector<int>& boundary) {
         if (node == nullptr) {
             return;
         }
         if (isLeaf(node)) {
             boundary.push_back(node->data);
             return;
         }
         addLeaves(node->left, boundary);
         addLeaves(node->right, boundary);
     }

     // Adds the right boundary in required bottom-up order.
     void addRightBoundary(Node* root, vector<int>& boundary) {
         Node* current = root->right;
         vector<int> rightBoundary;
         while (current != nullptr) {
             if (!isLeaf(current)) {
                 rightBoundary.push_back(current->data);
             }
             if (current->right != nullptr) {
                 current = current->right;
             } else {
                 current = current->left;
             }
         }
         // reverse since we walked top-down but need bottom-up
         for (int i = rightBoundary.size() - 1; i >= 0; i--) {
             boundary.push_back(rightBoundary[i]);
         }
     }

     vector<int> boundaryTraversal(Node* root) {
         vector<int> boundary;
         if (root == nullptr) {
             return boundary;
         }

         if (!isLeaf(root)) {
             boundary.push_back(root->data);
         }

         addLeftBoundary(root, boundary);
         addLeaves(root, boundary);
         addRightBoundary(root, boundary);

         return boundary;
     }
 };