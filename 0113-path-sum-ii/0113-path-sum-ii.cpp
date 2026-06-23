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
    void findPaths(TreeNode* root, int target, vector<int>& helper,vector<vector<int>>& ans) {
        if (!root) return;
        helper.push_back(root->val);
        if (!root->left && !root->right && target == root->val) {
            ans.push_back(helper);
        } else {
            findPaths(root->left, target - root->val, helper, ans);
            findPaths(root->right, target - root->val, helper, ans);
        }
        helper.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> helper;
        vector<vector<int>> ans;
        findPaths(root, target, helper, ans);
        return ans;
    }
};