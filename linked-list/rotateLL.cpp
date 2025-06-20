// Given the head of a linked list, rotate the list to the right by k places.

// Appraoch 1 - Using two-pointers
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k==0) return head;
        ListNode* temp = head;
        ListNode* fast = head;
        ListNode* slow = head;

        int size = 0;
        while(temp){
            temp = temp->next; size++;
        }

        k = k%size;
        if(k == 0) return head;

        int i=0; temp = head;
        while(temp && i++<k){
            fast = fast->next;
        }

        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode* newHead = slow->next;
        slow->next = NULL;
        fast->next = head;

        return newHead;
    }
};
// Time Complexity : O(2*n) , Space Complexity : O(1)

// Appraoch 2 - By circularing the LL
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k==0) return head;
        // size of LL
        ListNode* temp = head;
        int size = 0;
        while (temp) {
            temp = temp->next;
            size++;
        }
        k = k%size;
        if (k == 0) return head;

        // circular the LL
        temp = head;
        while (temp->next) temp = temp->next;
        temp->next = head;

        // find kth-1 node
        temp = head;
        for (int i = 0; i < size - k - 1; i++) {
            temp = temp->next;
        }
        // create newHead and connect remaining nodes
        ListNode* newHead = temp->next;
        temp->next = nullptr;

        return newHead;
    }
};
// Time Complexity : O(2*n) , Space Complexity : O(1)
