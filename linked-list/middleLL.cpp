// BRUTE APPROACH
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int size=1;
        ListNode* temp = head;
        while(temp->next != NULL){
            temp=temp->next;
            size++;
        }
        int mid = (size/2)+1;
        
        for(int pos = 1; pos < mid ; pos++ ){
            head=head->next;
        }
        return head;
    }
};
// TIME COMPLEXITY : O(N), Space Complexity : O(1)

//OPTIMAL APPROACH
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* 
        fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
};
// TIME COMPLEXITY : O(N), Space Complexity : O(1)

/* Explanation

Brute Force - count total nodes of linked list, return the total/2 th node as middle node
(Two pass)

Optimal Solution
- efficiently use slow and fast pointer
 - when slow pointer moves to next node, fast pointer moves by two nodes
- So, finally when fast pointer will be at tail node or pointing to NULL, slow pointer will be at mid
- Finally, return slow node
*/