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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode* , int>nodemap;

        ListNode *temp = head;

        while(temp){
            if(nodemap.find(temp) != nodemap.end()){
                return true;
            }
            nodemap[temp] = 1;

            temp = temp->next;
        }

        return false;


        
    }
};