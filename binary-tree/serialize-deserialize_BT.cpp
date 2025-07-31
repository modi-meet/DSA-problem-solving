// Serialize: convert tree to a single string.
// De-serialize: convert a string to tree.

/* 
Codec object will be instantiated and called as such:
    Codec ser, deser;
    TreeNode* ans = deser.deserialize(ser.serialize(root));
*/

// DFS Apporach
// preorder: node-left-right
class Codec {
public:   
    // result: "1,2,N,N,3,4,5,N,N,N,N"
    string serialize(TreeNode* root) {
        if(root == NULL) return "N";

        string leftStr = serialize(root->left);
        string rightStr = serialize(root->right);

        return to_string(root->val) + "," + leftStr + "," + rightStr;
    }

    TreeNode* deserialize(string data) {
        vector<string> preorder;

        stringstream ss(data);
        string token;

        while(getline(ss, token, ',')){
            preorder.push_back(token);
        }

        int idx = -1;
        return buildTree(preorder, idx);
    }
private:
    TreeNode* buildTree(vector<string>& preorder, int &idx){
        idx++;
        if(preorder[idx] == "N") return NULL;

        TreeNode* root = new TreeNode(stoi(preorder[idx]));

        root->left = buildTree(preorder, idx);
        root->right = buildTree(preorder, idx);

        return root;      
    }
};
// TC - O(n)
// SC - O(n)
//    - Serialization uses stack space proportional to tree height.
//    - Deserialization uses array for storing the tokens and recursion stack.

