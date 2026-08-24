class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return buildTrees(1, n);
    }
    
private:
    vector<TreeNode*> buildTrees(int start, int end) {
        vector<TreeNode*> allTrees;
        if (start > end) {
            allTrees.push_back(nullptr);
            return allTrees;
        }
        
        // Pick each number as root
        for (int rootVal = start; rootVal <= end; ++rootVal) {
            // Generate all possible left subtrees
            vector<TreeNode*> leftTrees = buildTrees(start, rootVal - 1);
            // Generate all possible right subtrees
            vector<TreeNode*> rightTrees = buildTrees(rootVal + 1, end);
        
            // Combine left and right subtrees with root
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(rootVal);
                    root->left = left;
                    root->right = right;
                    allTrees.push_back(root);
                }
            }
        }
        
        return allTrees;
    }
};
