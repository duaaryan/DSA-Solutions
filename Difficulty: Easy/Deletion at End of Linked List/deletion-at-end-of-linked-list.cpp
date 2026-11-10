/* Linked List Node Structure
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
public:
    Node* removeLastNode(Node* head) {
        // Case 1: If the list is empty
        if (head == nullptr) {
            return nullptr;
        }

        // Case 2: If the list has only one node
        if (head->next == nullptr) {
            delete head;
            return nullptr;
        }

        // Case 3: Traverse to the second-to-last node
        Node* curr = head;
        while (curr->next->next != nullptr) {
            curr = curr->next;
        }

        // Delete the last node and break the link
        delete curr->next;
        curr->next = nullptr;

        return head;
    }
};
