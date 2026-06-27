/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
unordered_map<int,int> mp;
    int preIdx=0;
    TreeNode* solve(vector<int>& preorder ,vector<int>& inorder, int l, int r){
        if(l > r) return NULL;
        TreeNode* root = new TreeNode(preorder[preIdx++]);
        int idx = mp[root->val];
        root->left = solve( preorder,inorder, l, idx - 1);
        root->right = solve( preorder,inorder, idx + 1, r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n =inorder.size();
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        return solve( preorder,inorder, 0, n - 1);
    }
};