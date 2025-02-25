class Solution {
public:
    // Function to reverse a linked list
    ListNode* reversee(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* prev = nullptr;
        ListNode* temp = head;

        while (temp != nullptr) {  // Fix: Loop until temp becomes NULL
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev; // New head of reversed list
    }

    // Function to check if the linked list is a palindrome
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;  // Empty or single-node list is always a palindrome
        }

        // Step 1: Find middle of the linked list
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half of the list
        ListNode* secondHalf = reversee(slow);
        ListNode* firstHalf = head;

        // Step 3: Compare both halves
        ListNode* temp = secondHalf;
        while (temp != nullptr) {
            if (firstHalf->val != temp->val) {
                return false;  // Mismatch found
            }
            firstHalf = firstHalf->next;
            temp = temp->next;
        }

        return true;  // List is a palindrome
    }
};
