/* Structure of binary tree node
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
    void serializeHelper(Node* root, vector<int>& arr) {
        if (root == nullptr) {
            arr.push_back(-1);   // null marker
            return;
        }
        arr.push_back(root->data);
        serializeHelper(root->left, arr);
        serializeHelper(root->right, arr);
    }

    vector<int> serialize(Node* root) {
        vector<int> arr;
        serializeHelper(root, arr);
        return arr;
    }

    Node* deserializeHelper(vector<int>& arr, int& index) {
        if (index >= arr.size() || arr[index] == -1) {
            index++;
            return nullptr;
        }

        Node* root = new Node(arr[index]);
        index++;

        root->left = deserializeHelper(arr, index);
        root->right = deserializeHelper(arr, index);

        return root;
    }

    Node* deSerialize(vector<int>& arr) {
        int index = 0;
        return deserializeHelper(arr, index);
    }
};