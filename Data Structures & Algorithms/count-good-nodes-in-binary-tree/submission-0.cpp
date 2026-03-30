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

//recursive DFS that tracks the lowest value seen so far


    auto dfs(TreeNode* root, int lowest_so_far, int& total_nodes){
        if(not root){
            return;
        }

        if(root->val >= lowest_so_far){
            total_nodes++;
        }

        lowest_so_far = max(lowest_so_far, root->val);

        dfs(root->right, lowest_so_far, total_nodes);
        dfs(root->left, lowest_so_far, total_nodes);

    } 
    int goodNodes(TreeNode* root) {
        int total_nodes = 1;
        dfs(root->right, root->val, total_nodes);
        dfs(root->left, root->val, total_nodes);

        return total_nodes;
    }
};
