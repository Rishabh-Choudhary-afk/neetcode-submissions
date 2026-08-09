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
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return head;
        }
        ListNode* prev=NULL;
        ListNode* temp=head;
        ListNode* next=head->next;
        while(temp!=NULL){
            temp->next=prev;
            prev=temp;
            temp=next;
            if(next!=NULL){
                next=next->next;
            }
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=reverseList(head);
        ListNode* a=temp;
        ListNode* prev=NULL;
        int cnt=1;
        while(cnt!=n){
            prev=temp;
            temp=temp->next;
            cnt++;
        }
        if(n==1){
            return reverseList(temp->next);
        }
        if(prev==NULL){
            return NULL;
        }
        prev->next=temp->next;
        temp->next=NULL;
        return reverseList(a);
    }
};
