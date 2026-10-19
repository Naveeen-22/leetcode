/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* findNthNode(ListNode*head , int k){
        int cnt =1;
        ListNode*temp = head;
        while(temp!=NULL){
            if(cnt==k) return temp;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0) return head;
        int len = 1;
        ListNode*tail = head ; 
        while(tail->next!=NULL){
            len+=1;
            tail = tail->next;
        }
        if(k%len==0){
            return head;
        }
    k = k%len;
    tail->next = head;
    ListNode*newNode = findNthNode(head , len-k);
    head = newNode->next;
    newNode->next = NULL;

    return head;
        
    }
};