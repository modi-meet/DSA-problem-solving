// Given the head of a linked list, remove the nth node from the end of the list.
// return its head.
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // ** two pass **
        ListNode* temp = head;
        int size = 0;
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }

        int nodeToBeRemoved = size - n;
        if (nodeToBeRemoved == 0){
            ListNode* newHead = head->next;
            delete head 
            return newHead;
        }

        temp = head;
        int count = 0;
        while (temp && temp->next) {
            count++;
            if (count == nodeToBeRemoved) {
                ListNode* gar = temp->next;
                temp->next = temp->next->next;
                delete gar;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};
// TIME COMPLEXITY : O(2*N), Space Complexity : O(1)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // ** one pass **
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = dummy;
        ListNode* sec = dummy;

        int i=0;
        while(i<=n){
            first = first->next;
            i++;
        }

        while(first){
            first = first->next;
            sec = sec->next;
        }
        
        //ListNode* temp = sec->next;
        sec->next = sec->next->next;
        //delete temp;

        return dummy->next;
    }
};
// TIME COMPLEXITY : O(N), Space Complexity : O(1)

/* Explanation
- Nth node from the end of the LL is required to be deleted
- if size of the LL is known, then (size-n+1) will give the node to be deleted
- This will lead to Intutive two-pass solution

How to create (size - n) difference b/w two nodes?
*OG Two-pointer technique of Linked-List:
    - move first pointer till n
    - now, move both first&sec pointer simultaneously; as the difference has been generated b/w them.
    - after complete traversal of the LL, sec will point to the one node previous to the node to be deleted
    - delete the node and join the connection. 

And, that's it!
*/