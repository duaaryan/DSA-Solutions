/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
public:
    Node* deleteNode(Node* head, int x) {
        if (head == nullptr) return head;

        if (x == 1) {
            Node* temp = head->next;
            delete head;
            return temp;
        }

        Node* curr = head;
        for (int i = 1; i < x - 1 && curr != nullptr; i++) {
            curr = curr->next;
        }
        if (curr == nullptr || curr->next == nullptr) return head;   // x list se bada hai

        Node* target = curr->next;
        curr->next = target->next;
        delete target;
        return head;
    }
};