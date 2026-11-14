/*
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
    Node *insertAtEnd(Node *head, int x) {
        Node* temp = new Node(x);
        if(head==nullptr){
            return temp;
        }
        
        Node* curr = head;
        while(curr->next !=nullptr){ 
        curr = curr->next;
        }
        curr->next = temp;
        
        return head;
        
    }
};