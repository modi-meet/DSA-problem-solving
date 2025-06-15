// group all the nodes with odd indices together followed by the nodes with even indices,
// return the reordered list.
// The first node is considered odd, and the second node is even, and so on.
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* EvenStart = head->next;

        while(even && even->next){
            odd->next = even->next; // increament by 1
            even->next = even->next->next; // increament by 2

            odd = odd->next;
            even = even->next;
        }
        odd->next = EvenStart;
        return head;
    }
};
// TIME COMPLEXITY: O(N), Space Complexity: O(1)