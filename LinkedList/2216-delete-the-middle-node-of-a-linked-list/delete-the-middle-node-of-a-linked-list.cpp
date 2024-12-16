class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Step 1: Count the total number of nodes
        ListNode *temp = head;
        int count = 0;
        while (temp) {
            count++;
            temp = temp->next;
        }

        if(count == 1){
            return NULL;
        }
        

        if(count == 2){
            int mid = 1;
            ListNode * Next = head->next;
            head->next = NULL;
            delete Next;

            return head;


        }

        // Step 2: Find the middle node
        int mid = count / 2;
        ListNode *prev = head;

        // Traverse to the middle node
        for (int i = 0; i < mid; i++) {
            prev = prev->next;
        }

        // Step 3: Copy value of the next node into the middle node
        prev->val = prev->next->val;

        // Step 4: Update pointer to bypass the next node
        ListNode *Next = prev->next;
        prev->next = prev->next->next;

        // Step 5: Delete the next node
        delete Next;

        return head; // Return the updated list
    }
};
