class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dum = new ListNode(0); 
        ListNode* temp = dum; 
        int car = 0; 

        while (l1 != nullptr || l2 != nullptr || car != 0) {
            int sum = car;

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val; 
                l2 = l2->next; 
            }

            car = sum / 10; 
            temp->next = new ListNode(sum % 10); 
            temp = temp->next;
        }

        return dum->next; 
    }
};