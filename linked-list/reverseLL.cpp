// Reverse the Linked List
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr= head;
        ListNode* next = NULL;

        while(curr != NULL){
            curr->next = prev;
            prev = curr;
            curr = next;
            next = curr->next;
        }
        return prev;
    }
};
// TIME COMPLEXITY: O(N), Space Complexity : O(1)

/* Explanation
To reverse the Linked List
    - maintain three pointers : curr, prev, next
    - curr points to current node, prev to the previous node & next to the next node of Current node
    1. remove curr.next connection
    2. connect currnt node to prev
    3. update prev, curr and next pointers
*/