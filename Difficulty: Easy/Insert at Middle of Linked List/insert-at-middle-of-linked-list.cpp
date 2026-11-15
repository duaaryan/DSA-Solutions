/* Strucutre of a link list node
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
    Node *insertInMiddle(Node *head, int x) {
       Node* temp = new Node(x);
       
       if(head == nullptr) return temp;
       
       Node* curr = head;
       Node* fast = head->next;
       
       while(fast != nullptr && fast->next !=nullptr){
           curr = curr->next;
           fast = fast->next->next;
       }
       
       temp->next = curr->next;
       curr->next = temp;
       
       return head;
        
    }
};