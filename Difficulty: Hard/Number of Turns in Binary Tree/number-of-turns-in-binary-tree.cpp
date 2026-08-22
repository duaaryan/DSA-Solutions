/* Structure of Binary Tree Node
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
private:
    // Helper function to find the Lowest Common Ancestor
    Node* findLCA(Node* root, int p, int q) {
        if (!root || root->data == p || root->data == q) {
            return root;
        }

        Node* leftLCA = findLCA(root->left, p, q);
        Node* rightLCA = findLCA(root->right, p, q);

        if (leftLCA && rightLCA) return root;
        return (leftLCA != nullptr) ? leftLCA : rightLCA;
    }

    // Helper function to count turns from a starting node to a target value
    // 'dir' represents the current direction: true for Left, false for Right
    bool countTurnsUtil(Node* root, int target, bool dir, int &turns) {
        if (!root) return false;
        if (root->data == target) return true;

        // Try moving Left
        if (countTurnsUtil(root->left, target, true, turns)) {
            // If previous step was Right, direction changed -> increment turn
            if (!dir) turns++;
            return true;
        }

        // Try moving Right
        if (countTurnsUtil(root->right, target, false, turns)) {
            // If previous step was Left, direction changed -> increment turn
            if (dir) turns++;
            return true;
        }

        return false;
    }

public:
    int numberOfTurns(Node* root, int p, int q) {
        if (!root || p == q) return -1;

        Node* lca = findLCA(root, p, q);
        if (!lca) return -1;

        int totalTurns = 0;

        // Case 1: LCA is one of the two target nodes
        if (lca->data == p) {
            // Path goes straight down from p to q
            if (countTurnsUtil(lca->left, q, true, totalTurns) || 
                countTurnsUtil(lca->right, q, false, totalTurns)) {
                return (totalTurns == 0) ? -1 : totalTurns;
            }
        }
        else if (lca->data == q) {
            // Path goes straight down from q to p
            if (countTurnsUtil(lca->left, p, true, totalTurns) || 
                countTurnsUtil(lca->right, p, false, totalTurns)) {
                return (totalTurns == 0) ? -1 : totalTurns;
            }
        }
        // Case 2: LCA is a distinct common ancestor
        else {
            // Check if one node is on the left subtree and the other is on the right
            bool pInLeft = countTurnsUtil(lca->left, p, true, totalTurns);
            bool qInLeft = pInLeft ? false : countTurnsUtil(lca->left, q, true, totalTurns);

            if (pInLeft) {
                countTurnsUtil(lca->right, q, false, totalTurns);
            } else {
                countTurnsUtil(lca->right, p, false, totalTurns);
            }

            // There is always a turning point at the LCA itself between left and right branches
            return totalTurns + 1;
        }

        return -1;
    }
};
