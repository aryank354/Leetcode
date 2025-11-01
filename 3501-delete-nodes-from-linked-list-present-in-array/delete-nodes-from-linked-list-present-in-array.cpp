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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st(begin(nums), end(nums));
        if (!head) return nullptr;

        // Handling the head
        while(st.find(head->val) != st.end()){
            head = head->next;
        }

        if (!head) return nullptr;

        // Handling if the deleting element is not head
        ListNode * curr = head;
        while(curr->next != NULL){
            if(st.find(curr->next->val) != st.end()){
                curr->next = curr->next->next;
            }
            else{
                curr = curr->next;
            }

        }

        return head;
    

    }
};