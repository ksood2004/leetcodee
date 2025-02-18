/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteel(ListNode* node, int ele) {
        if (node == NULL) {
            return NULL;
        }

        // If the node to be deleted is the head
        if (node->val == ele) {
            ListNode* temp = node;
            node = node->next;
            delete temp;
            return node;
        }

        ListNode* prev = NULL;
        ListNode* temp = node;

        while (temp != NULL) {
            if (temp->val == ele) {
                prev->next = temp->next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return node;  // Return the modified list head
    }

    void deleteNode(ListNode* node) {
     
        if (node == NULL || node->next == NULL) return;

        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
};
