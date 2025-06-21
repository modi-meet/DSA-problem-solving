// Given the head of a linked list and a value x, 
// partition it such that all nodes less than x come before nodes greater than or equal to x.
// Preserve the original relative order of the nodes

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL) return NULL;
        ListNode* smallHead = new ListNode(-1);
        ListNode* largeHead = new ListNode(-1);
        ListNode* s_temp = smallHead; // traverse in smallLL
        ListNode* l_temp = largeHead; // traverse in largeLL
        ListNode* temp = head;

        while(temp){
            if(temp->val < x) {
                s_temp->next = temp;
                s_temp = s_temp->next;
            } else {
                l_temp->next = temp;
                l_temp = l_temp->next;
            }
            temp = temp->next;
        }  

        l_temp->next = NULL;
        s_temp->next = largeHead->next;

        return smallHead->next;
    }
};
// Time Complexity: O(n), Space Complexity: O(1)