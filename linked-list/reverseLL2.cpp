// Given the head of a a linked list and two integers left and right,
// reverse the nodes of the list from position left to position right, and return the reversed list.
class Solution {
public:
    ListNode* reverseLL(ListNode* curr, int left, int right){
        ListNode* next = NULL;
        ListNode* prev = NULL; 
        ListNode* oldCurr = curr; // store value for main LL connection later

        while(left <= right && curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            left++;
        }
        oldCurr->next = curr; // Connect end of reversed LL to rest of list
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;

        int i=1;
        while(i < left){
            prev = prev->next;
            i++;
        }

        ListNode* newHead = reverseLL(prev->next, i, right);
        prev->next = newHead; // Now prev->next is the start of the reversed part

        return dummy->next;
    }
};
// Time complexity : O(N), Space complexity : O(1) + O(N) (dummy nodes)

/* Explanation
Since the LL should be reversed only b/w left and right nodes,
    - apple LL reversal only to range [left,right] nodes
    - unlike normal reversal of a LL, here connection of reversed part with original LL is required!
        - Connect reversed LL head to the previous node of `left`
        - Connect reversed LL tail to the next node of `right`
And, that's it!
*/