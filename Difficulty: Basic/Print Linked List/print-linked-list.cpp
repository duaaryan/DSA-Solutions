/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    void printList(Node* head) {
       Node* curr = head;

    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
        
    }
};