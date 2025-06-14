// Add 2 numbers
// Given 2 Linked list (L1, L2), return an answer LL which has node values 
// equivalent to the sum of corresponding nodes in L1 and L2
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        int carry = 0;

        while(l1 || l2 || carry){
            int sum = carry;
            
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            } 
            if(l2){
                sum  += l2->val;
                l2 = l2->next;
            }
            // update carry and add newNode to LL
            carry = sum / 10;          //  14/10 = 1
            temp->next = new ListNode(sum % 10);   //   14%10 = 4
            temp = temp->next;
        }
        
        return ans->next;
    }
};
// TIME COMPLEXITY : O(N), SC - O(1)

/*
Explanation

Factors to consider- 
1. what if both LL are of different sizes?
2. What if sum has carry
3. What is carry remains after tail node?

Approach - initialize a new LL called `ans` with node value 0
         - take initial carry as 0
         - iterate through both the LLs
         - everytime add L1 node and L2 node values to sum and calculate carry
            - if carry is there, update it.
        - add the sum value as new ans Node
        - Iterate till either of the two LL exist or carry exist;           
            - if after both LLs are done, still carry exist; add it as new Node
        - return ans.next pointer as Head of resultant LL (as initialzed with 0 at the begining) 
*/