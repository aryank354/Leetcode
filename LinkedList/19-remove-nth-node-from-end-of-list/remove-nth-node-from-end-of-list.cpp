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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        // Calculate the length of the list
        int length = 0;
        ListNode* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }

        // Find the position from the start to remove
        int s = length - n;

        // Traverse to the node to be removed
        while (s--) {
            prev = curr;  // Update prev before advancing curr
            curr = curr->next;
        }

        // If the node to remove is the head
        if (prev == nullptr) {
            head = head->next;  // Move the head pointer
            delete curr;        // Delete the original head
        } else {
            prev->next = curr->next;  // Bypass the current node
            delete curr;              // Delete the node
        }

        return head;
    }
        
    
};