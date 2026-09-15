/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
public:
    // Helper function to find all leaf node costs using DFS
    void getLeafCosts(Node* root, int currentLevel, std::vector<int>& leafCosts) {
        if (root == nullptr) {
            return;
        }

        // Check if the current node is a leaf node
        if (root->left == nullptr && root->right == nullptr) {
            leafCosts.push_back(currentLevel);
            return;
        }

        // Recur for left and right subtrees increasing the level
        getLeafCosts(root->left, currentLevel + 1, leafCosts);
        getLeafCosts(root->right, currentLevel + 1, leafCosts);
    }

    int getCount(Node* root, int k) {
        std::vector<int> leafCosts;

        // 1. Collect all leaf costs starting from root at level 1
        getLeafCosts(root, 1, leafCosts);

        // 2. Sort costs in ascending order to pick the cheapest leaves first
        std::sort(leafCosts.begin(), leafCosts.end());

        int count = 0;

        // 3. Greedily pick leaves within the budget k
        for (int cost : leafCosts) {
            if (k >= cost) {
                k -= cost;
                count++;
            } else {
                break; // Remaining leaves are too expensive
            }
        }

        return count;
    }
};
