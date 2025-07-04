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
ListNode* reversee(ListNode* head){
    if(head==NULL){
        return NULL;
    }

    ListNode* prev=NULL;
    ListNode* temp=head;

    while(temp!=NULL){
        ListNode* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}
    bool isPalindrome(ListNode* head) {
        if(head==NULL){
            return false;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* secondhalf=reversee(slow);
        ListNode* firsthalf=head;
        ListNode* temp=secondhalf;
        while(temp!=NULL){
            if(head->val!=temp->val){
                return false;
            }
            firsthalf=firsthalf->next;
            temp=temp->next;
        }
        return true;


    }
};