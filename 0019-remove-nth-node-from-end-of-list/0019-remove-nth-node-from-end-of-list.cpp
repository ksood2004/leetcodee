class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
            return NULL;
        }

        int cnt = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        if (cnt == n) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        temp = head;
        int pos = cnt - n; 
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }

      
        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;

        return head;
    }
};
