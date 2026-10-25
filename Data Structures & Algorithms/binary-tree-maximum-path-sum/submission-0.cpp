class Solution {
public:
    int max_sum = numeric_limits<int>::min();

    auto dfs(TreeNode* curr) -> int {
        if (not curr) return 0;

        auto max_left = std::max(0, dfs(curr->left));
        auto max_right = std::max(0, dfs(curr->right));

        // Best complete path passing through this node
        max_sum = std::max(
            max_sum,
            curr->val + max_left + max_right
        );

        // Best path that can be extended by the parent
        return curr->val + std::max(max_left, max_right);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return max_sum;
    }
};