/* Structure of Linked List Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    bool searchKey(Node* head, int key) {
         
        Node* curr = head;
        
        while(curr != nullptr){
            if(curr->data == key){
                return true;
            }
            curr= curr->next;
        }
        return false;
    }
};
