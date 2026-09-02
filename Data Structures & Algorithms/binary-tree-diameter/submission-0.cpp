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
      int diameter = 0;

    int height(TreeNode* curr) {
        if (!curr) {
            return 0;
        }

        int left = height(curr->left);
        int right = height(curr->right);

        // Longest path passing through curr
        diameter = std::max(diameter, left + right);

        // Height of curr
        return 1 + std::max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};
