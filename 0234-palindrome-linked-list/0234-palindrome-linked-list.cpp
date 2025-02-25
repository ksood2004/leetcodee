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
    bool isPalindrome(ListNode* head) {
        vector<int> values;  // Step 1: Store values in an array

        ListNode* temp = head;
        while (temp != nullptr) {
            values.push_back(temp->val);
            temp = temp->next;
        }

        int left = 0, right = values.size() - 1;

        // Step 2: Check if array is a palindrome
        while (left < right) {
            if (values[left] != values[right]) {
                return false;  // Mismatch found
            }
            left++;
            right--;
        }

        return true; 
    }
};