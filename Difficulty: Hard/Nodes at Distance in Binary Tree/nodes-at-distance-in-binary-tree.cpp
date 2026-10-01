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
};
*/
class Solution {
public:
    void markParents(Node* root, unordered_map<Node*, Node*>& parentMap) {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            if (node->left) {
                parentMap[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }
    }

    Node* findNode(Node* root, int target) {
        if (root == nullptr) return nullptr;
        if (root->data == target) return root;

        Node* left = findNode(root->left, target);
        if (left) return left;

        return findNode(root->right, target);
    }

    vector<int> kDistanceNodes(Node* root, int target, int k) {
        vector<int> result;

        unordered_map<Node*, Node*> parentMap;
        markParents(root, parentMap);

        Node* targetNode = findNode(root, target);
        if (targetNode == nullptr) return result;

        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;
        int curLevel = 0;

        while (!q.empty()) {
            int size = q.size();
            if (curLevel == k) break;

            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();

                if (node->left && !visited[node->left]) {
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if (node->right && !visited[node->right]) {
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if (parentMap[node] && !visited[parentMap[node]]) {
                    visited[parentMap[node]] = true;
                    q.push(parentMap[node]);
                }
            }
            curLevel++;
        }

        while (!q.empty()) {
            result.push_back(q.front()->data);
            q.pop();
        }

        sort(result.begin(), result.end());
        return result;
    }
};