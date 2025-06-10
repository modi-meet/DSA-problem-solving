/*
Convert Sorted List to Binary Search Tree

ListNode* is a LinkedList in non-decreasing order
*/

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return new TreeNode(head->val);

        ListNode* slow = head; ListNode* fast = head;
        ListNode* slowKaPrev = NULL;

        while(fast && fast->next) { //O(n)
            slowKaPrev = slow;

            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* node = new TreeNode(slow->val);

        slowKaPrev->next = NULL; //break the connection from slow ka prev to mid node

        node->left = sortedListToBST(head);
        node->right = sortedListToBST(slow->next);

        return node;
    }
};

// Time Complexity : O(N*logN) , logN - height of the tree to build the tree
//                               O(n) - each call counts miid by slow-fast technique 

/* Explanation

To find the middle node of the LinkedList,
    - Use slow-fast pointer technique.

After finding the middle node, 
    1. create left subtree,
    2. create right subtree (Recursively)

    3. remove the connection of the node prior to middle node; it going to be in leftSubtree
        - we keep the connection of the node next to midnode as it will become head for right subtree

    //base case will be, if root becomes null we return null node.  
*/