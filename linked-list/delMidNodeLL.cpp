// Delete the middle node of the given Linked List, given the head.
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) // base case
            return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        fast = head->next->next; //skip 1 slow->next

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return head;
    }
};
// TIME COMPLEXITY: O(N), Space Complexity : O(1)

// Alternate approach
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
    ListNode* temp = head;
        int n = 0;

        while(temp) {
            temp = temp->next;
            n++;
        }
        int mid = n / 2;
        ListNode* curr = head;
        ListNode* prev = head;

        for (int i = 0; i < mid; i++) {
            prev = curr;
            curr = curr->next;
        } // curr is pointing to mid node which is supposed to be removed
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

        return head;
    }
};
// TIME COMPLEXITY: O(N), Space Complexity : O(1)