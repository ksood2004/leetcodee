class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr; // No cycle possible
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect cycle using slow & fast pointers
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next; // Fix: Move fast by two steps

            if (slow == fast) { // Cycle detected
                break;
            }
        }

        // Step 2: If no cycle was found
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr; // No cycle
        }

        // Step 3: Find the start of the cycle
        slow = head; // Move fast to head
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow; // Start of the cycle
    }
};
