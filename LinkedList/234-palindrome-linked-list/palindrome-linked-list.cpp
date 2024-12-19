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
        // stack<int>st;

        // ListNode *temp = head;



        // while(temp){
        //     st.push(temp->val);
        //     temp = temp->next;
        // }

        // temp = head;

        // while(temp){
        //     if(temp->val != st.top()){
        //         return false;
        //     }
        //     temp = temp->next;
        //     st.pop();

        // }

        // return true;
        

        ListNode * slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }


        ListNode * curr = slow;
        ListNode * prev = NULL;

        while(curr != NULL){
            ListNode * front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        ListNode * first = head;
        ListNode *second = prev;

        while(second){
            if(first->val != second->val){
                return false;
            }

            first = first->next;
            second = second->next;
        }

        return true;

        
    }
};