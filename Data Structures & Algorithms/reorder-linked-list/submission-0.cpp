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
    void reorderList(ListNode* head) {
        ListNode* mid = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            mid = mid->next;
            fast = fast->next->next;
        }
        ListNode* curr2 = reverseList(mid->next);
        mid->next = NULL;
        ListNode* curr1 = head;

        while(curr2 != NULL) {
            ListNode* next1 = curr1->next;
            ListNode* next2 = curr2->next;

            curr1->next = curr2;
            curr2->next = next1;

            curr1 = next1;
            curr2 = next2;
        }
    }
};
