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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        if(l1==NULL && l2==NULL){
            return NULL;
        }
        ListNode* head=NULL;
        ListNode* curr=NULL;
        while(l1!=NULL && l2!=NULL){
            int sum=(l1->val+l2->val)+carry;
            int value=sum%10;
            carry=sum/10;
            ListNode* newnode=new ListNode(value);
            if(head==NULL){
                head=newnode;
                curr=newnode;
            }else{
                curr->next=newnode;
                curr=newnode;
            }
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            int sum=(l1->val)+carry;
            int value=sum%10;
            carry=sum/10;
            ListNode* newnode=new ListNode(value);
            if(head==NULL){
                head=newnode;
                curr=newnode;
            }else{
                curr->next=newnode;
                curr=newnode;
            }
            l1=l1->next;
        }
        while(l2!=NULL){
            int sum=(l2->val)+carry;
            int value=sum%10;
            carry=sum/10;
            ListNode* newnode=new ListNode(value);
            if(head==NULL){
                head=newnode;
                curr=newnode;
            }else{
                curr->next=newnode;
                curr=newnode;
            }
            l2=l2->next;
        }
        if(carry!=0){
            ListNode* newnode=new ListNode(carry);
            curr->next=newnode;
        }
        return head;
    }
};
