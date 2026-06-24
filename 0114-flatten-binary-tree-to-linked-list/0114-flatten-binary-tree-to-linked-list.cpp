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
    // void preorder(TreeNode* root , vector<TreeNode*> & ans){
    //     if(root == NULL) return;
    //     ans.push_back(root);
    //     preorder(root->left,ans);
    //     preorder(root->right,ans);
    // }
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr != NULL) {
            if(curr->left != NULL) {
                // predecessor = left subtree ka rightmost node
                TreeNode* pred = curr->left;
                while(pred->right != NULL) {
                    pred = pred->right;
                }
                // original right subtree ko predecessor ke right me jod do
                pred->right = curr->right;
                // left subtree ko right me shift karo
                curr->right = curr->left;
                curr->left = NULL;
            }
            // next node
            curr = curr->right;
    }
    }
};