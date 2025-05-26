/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node* newnode = new Node(data);
        if(!head){
            newnode->next = head;
            return newnode;
        }
        Node* curr = head;
        if (data < head->data) {
            while (curr->next != head) {
                curr = curr->next;
            }
            curr->next = newnode;
            newnode->next = head;
            return newnode;
        }
        while(curr->next!=head && curr->next->data < data){
            curr = curr->next;
        }
        newnode->next = curr->next;
        curr->next = newnode;
        return head;
    }
};