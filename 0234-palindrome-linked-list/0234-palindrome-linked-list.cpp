class Solution {
public:
    ListNode* reversee(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* prev = nullptr;
        ListNode* temp = head;
        while (temp != nullptr) { 
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev; 
    }
    // Function to check if the linked list is a palindrome
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true; 
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHalf = reversee(slow);
        ListNode* firstHalf = head;
        ListNode* temp = secondHalf;
        while (temp != nullptr) {
            if (firstHalf->val != temp->val) {
                return false;  
            }
            firstHalf = firstHalf->next;
            temp = temp->next;
        }

        return true;  
    }
};
