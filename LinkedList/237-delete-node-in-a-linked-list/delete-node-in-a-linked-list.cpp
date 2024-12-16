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
    void deleteNode(ListNode* node) {
        // Copy the value of the next node into the current node
        node->val = node->next->val;

        // Save the node to be deleted
        ListNode* temp = node->next;

        // Skip the next node
        node->next = node->next->next;

        // Free the memory of the deleted node
        delete temp;
    }
};
