/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL){
            return head;
        }
        Node*curr = head;
        while(curr!=NULL){
            if(curr->child!=NULL){
                Node*temp = curr->next;
                Node*childN = curr->child;

                curr->next = childN;
                childN->prev = curr;
                curr->child = NULL;

                Node*tail = childN;
                while(tail->next!=NULL){
                    tail = tail->next;
                }
                if(temp!=NULL){
                    tail->next = temp;
                    temp->prev = tail;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};