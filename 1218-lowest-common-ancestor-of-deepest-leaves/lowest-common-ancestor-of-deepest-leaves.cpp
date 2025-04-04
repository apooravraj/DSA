class Solution {
public:
    // Helper function that returns a pair: {depth, LCA}
    pair<int, TreeNode*> solve(TreeNode* root) {
        if (!root) return {0, nullptr};
        
        auto l = solve(root->left);
        auto r = solve(root->right);
        
        if (l.first == r.first) {
            return {l.first + 1, root};
        } else if (l.first > r.first) {
            return {l.first + 1, l.second};
        } else {
            return {r.first + 1, r.second};
        }
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return solve(root).second;
    }
};
