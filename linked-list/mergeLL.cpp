// Merge two sorted Linked Lists
class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* ans = new ListNode(0);
    ListNode* temp = ans;

    while(l1 || l2){
        ListNode* node = nullptr;
        if(l1 && l2){
            node = new ListNode(min(l1->val, l2->val)); // extra space

            if(l1->val < l2->val) l1 = l1->next;
            else l2 = l2->next;
        } 
        else if(l1) {
            node = new ListNode(l1->val);  // extra space
            l1 = l1->next;
        } else{
            node = new ListNode(l2->val);   // extra space
            l2 = l2->next;
        }

        temp->next = node;
        temp = temp->next;
    }
    return ans->next;
  }
}; 
//TIME COMPLEXITY : O(N1 + N2), Space Complexity : O(N1+N2)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        else if (l2 == NULL) return l1;
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans; 

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        temp->next = l1 ? l1 : l2;
        return ans->next;
    }
};
//TIME COMPLEXITY : O(N1 + N2), Space Complexity : O(1)

/* Explanation
Approach 1 - Simply performing merge sort algorithm using two-pointer concept on Linked list
           - and, storing answer in the new LL

Approach 2 - Similar logic as approach-1 but efficiently reducing the extra space taken
           - By reducing the unnecessary adding of new Node everytime
           - Instead, using the same node in L1 & L2 and changing the connection according to sorting expectation!

And, that's it!
*/