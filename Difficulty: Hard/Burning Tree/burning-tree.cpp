/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

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

    Node* findTarget(Node* root, int target) {
        if (root == nullptr) return nullptr;
        if (root->data == target) return root;
        Node* left = findTarget(root->left, target);
        if (left) return left;
        return findTarget(root->right, target);
    }

    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parentMap;
        markParents(root, parentMap);

        Node* targetNode = findTarget(root, target);

        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool spreadHappened = false;

            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();

                if (node->left && !visited[node->left]) {
                    visited[node->left] = true;
                    q.push(node->left);
                    spreadHappened = true;
                }
                if (node->right && !visited[node->right]) {
                    visited[node->right] = true;
                    q.push(node->right);
                    spreadHappened = true;
                }
                if (parentMap[node] && !visited[parentMap[node]]) {
                    visited[parentMap[node]] = true;
                    q.push(parentMap[node]);
                    spreadHappened = true;
                }
            }

            if (spreadHappened) time++;
        }

        return time;
    }
};