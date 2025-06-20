/*
Given the head of a sorted linked list, 
delete all nodes that have duplicate numbers, leaving only distinct numbers
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* temp = new ListNode(0, head);
        // temp->next = head;
        ListNode* prev = temp;

        while (head) {
            if (head->next && head->val == head->next->val) {
                while (head->next && head->val == head->next->val) {
                       head = head->next;
                }

                prev->next = head->next;
            } else {
                prev = prev->next;
            }

        head = head->next;

    }
        return temp->next;
    }
};
// Time Complexity : O(N), Space complexity : O(1) + O(N) (temp node)