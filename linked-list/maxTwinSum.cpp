/*
Maximum Twin Sum of a Linked List
the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node
The twin sum is defined as the sum of a node and its twin.
*/
class Solution {
public:
    int pairSum(ListNode* head) {
        if (head == NULL || head->next == NULL) return 0; // base case
        // get the middle node in order to reverse the second half of LL
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse the second half of the LL
        ListNode* midHead = reverseLL(slow);
        // find the max sum by traversing through first and second half of LL
        // simultaneously
        int maxSum = 0;
        while (midHead) {
            maxSum = max(maxSum, head->val + midHead->val);
            head = head->next;
            midHead = midHead->next;
        }
        return maxSum;
    }
private: 
    ListNode* reverseLL(ListNode* node){ // function to reverse the LL
        ListNode* prev = nullptr;
        ListNode* curr = node;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }   
};
// TIME COMPLEXITY: O(N), Space Complexity : O(1)