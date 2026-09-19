/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
    bool isIdentical(Node* r1, Node* r2) {
       if(r1 == nullptr || r2 == nullptr){
           return (r1==r2);
       }
       return (r1->data == r2 ->data)
       && isIdentical(r1->left, r2->left)
       && isIdentical(r1->right, r2->right);
        
    }
};