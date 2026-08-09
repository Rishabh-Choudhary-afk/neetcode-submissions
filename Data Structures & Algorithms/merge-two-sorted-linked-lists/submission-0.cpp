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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL){
            return NULL;
        }else if(list1==NULL && list2!=NULL){
            return list2;
        }else if(list1!=NULL && list2==NULL){
            return list1;
        }
        ListNode* head=NULL;
        ListNode* tail=NULL;
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        while(temp1!=NULL && temp2!=NULL){
            int d=min(temp1->val,temp2->val);
            ListNode* newnode=new ListNode(d);
            if(head==NULL){
                head=newnode;
                tail=newnode;
            }else{
                tail->next=newnode;
                tail=newnode;
            }
            if(temp1->val<=temp2->val){
                temp1=temp1->next;
            }else{
                temp2=temp2->next;
            }
        }
        while(temp1!=NULL){
            ListNode* newnode=new ListNode(temp1->val);
            tail->next=newnode;
            tail=newnode;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            ListNode* newnode=new ListNode(temp2->val);
            tail->next=newnode;
            tail=newnode;
            temp2=temp2->next;
        }
        return head;
    }
};
