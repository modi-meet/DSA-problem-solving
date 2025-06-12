// Given head, determine if the linked list has a cycle in it. cycle means when a node's next pointer points to any previous 
// node creating contiguos Linked list cycle
class Solution {
public: // Brute Force
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        ListNode* temp = head;
        while(temp != NULL){
            if(set.count(temp)) return true;

            set.insert(temp);
            temp = temp->next;
        }
        return false;
    }
};
// TIME COMPLEXITY : O(N), Space Complexity : O(N) (using set)

class Solution {
public: // Optimal Solution
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};
// TIME COMPLEXITY : O(N), Space Complexity : O(1)

/*
Explanation
If there exist a cycle in a LL, that means there is no node pointing to NULL address

Brute Force - use a set to store unique nodes
    - if current node is found in the set, means there is a cycle in the LL; return true
    - return false, otherwise; No cycle found.

Optimal Solution - using fast & slow pointers
    - increase slow by 1 and fast by 2
    - if the LL is circular, both slow and fast pointer will definitely meet at one same node; return true
    - for linear LL, iterate till fast exist && fast->next exist.
    - if loop ends means, we found NULL address; meaning it's a Linear LL, return false.
*/
