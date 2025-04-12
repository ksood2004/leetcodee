class Solution {
public:
    // Helper 1: Get the kth node from current
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr && k > 1) {
            curr = curr->next;
            k--;
        }
        return curr;
    }

    // Helper 2: Reverse a section of the list
    void reverse(ListNode* start, ListNode* end) {
        ListNode* prev = end->next;
        ListNode* curr = start;

        while (prev != end) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
    }

    // Main Function: Reverse nodes in k groups
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;

        while (true) {
            ListNode* kth = getKthNode(groupPrev->next, k);
            if (!kth) break;

            ListNode* groupStart = groupPrev->next;
            ListNode* groupNext = kth->next;

            // Reverse current group
            reverse(groupStart, kth);

            // Connect previous part with reversed group
            groupPrev->next = kth;
            groupPrev = groupStart; // move to end of this reversed group
        }

        return dummy.next;
    }
};
