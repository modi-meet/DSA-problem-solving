// Check whether both the trees are same or not
class Solution {
public:
    bool isSame(TreeNode* p, TreeNode* q){
        if(p == NULL || q == NULL)
            return p==q;

        bool leftsame = isSame(p->left, q->left);
        bool rightsame = isSame(p->right, q->right);

        return leftsame && rightsame && p->val == q->val;
    } 

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSame(p, q);
    }
};
// Time Complexity: O(n)
