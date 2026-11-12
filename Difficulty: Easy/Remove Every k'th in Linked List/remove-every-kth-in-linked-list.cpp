/* Structure for Link list node
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* deleteK(Node* head, int K) {
        // Edge case: empty list or invalid K
        if (head == nullptr || K <= 0) {
            return head;
        }

        // Edge case: K = 1 means every node is deleted
        if (K == 1) {
            while (head != nullptr) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            return nullptr;
        }

        Node* curr = head;
        Node* prev = nullptr;
        int count = 0;

        while (curr != nullptr) {
            count++;

            // If current position is a multiple of K, delete the node
            if (count % K == 0) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};
