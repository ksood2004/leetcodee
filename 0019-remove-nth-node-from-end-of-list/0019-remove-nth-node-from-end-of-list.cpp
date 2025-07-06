class Solution {
public:
    ListNode* reversee(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* prev = NULL;
        ListNode* temp = head;
        while (temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
            return NULL;
        }

        int cnt = 1;
        ListNode* revHead = reversee(head);
        ListNode* temp = revHead;
        ListNode* prev = NULL;

        while (temp != NULL) {
            if (cnt == n) {
                if (prev == NULL) {
                    revHead = temp->next;  // removing the first node
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                break;
            }
            cnt++;
            prev = temp;
            temp = temp->next;
        }

        return reversee(revHead);  // <- fix: reverse modified list, not original head
    }
};
