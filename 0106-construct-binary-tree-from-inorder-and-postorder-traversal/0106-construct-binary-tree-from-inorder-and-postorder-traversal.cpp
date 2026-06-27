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
    int postIdx;
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int l, int r){
        if(l > r) return NULL;
        TreeNode* root = new TreeNode(postorder[postIdx--]);
        int idx = mp[root->val];
        root->right = solve(inorder, postorder, idx + 1, r);
        root->left = solve(inorder, postorder, l, idx - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n =inorder.size();
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        postIdx = n - 1;
        return solve(inorder, postorder, 0, n - 1);
    }
};