/* BST Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

/* BST Node Structure 
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
private:
    // Helper function to merge two sorted halves and count inversions
    int mergeAndCount(vector<int>& arr, int l, int m, int r) {
        vector<int> leftArr(arr.begin() + l, arr.begin() + m + 1);
        vector<int> rightArr(arr.begin() + m + 1, arr.begin() + r + 1);

        int i = 0, j = 0, k = l;
        int inversions = 0;

        while (i < leftArr.size() && j < rightArr.size()) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k++] = leftArr[i++];
            } else {
                arr[k++] = rightArr[j++];
                // If leftArr[i] > rightArr[j], then all remaining elements 
                // in leftArr from index i to the end form violating pairs
                inversions += (leftArr.size() - i);
            }
        }

        while (i < leftArr.size()) arr[k++] = leftArr[i++];
        while (j < rightArr.size()) arr[k++] = rightArr[j++];

        return inversions;
    }

    // Standard Merge Sort that counts inversions
    int mergeSortAndCount(vector<int>& arr, int l, int r) {
        int count = 0;
        if (l < r) {
            int m = l + (r - l) / 2;
            count += mergeSortAndCount(arr, l, m);
            count += mergeSortAndCount(arr, m + 1, r);
            count += mergeAndCount(arr, l, m, r);
        }
        return count;
    }

    // Helper function to extract the inorder traversal sequence
    void storeInorder(Node* root, vector<int>& arr) {
        if (!root) return;
        storeInorder(root->left, arr);
        arr.push_back(root->data);
        storeInorder(root->right, arr);
    }

public:
    int pairsViolatingBST(Node* root) {
        vector<int> inorderSequence;
        storeInorder(root, inorderSequence);

        if (inorderSequence.empty()) return 0;

        return mergeSortAndCount(inorderSequence, 0, inorderSequence.size() - 1);
    }
};
