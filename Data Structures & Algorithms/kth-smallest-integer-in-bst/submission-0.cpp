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

    auto dfs(TreeNode* root, vector<TreeNode*>& path){
        if(not root ) return;

       
            dfs(root->right, path);
        
        path.push_back(root);
            dfs(root->left, path);
        
        

        
    }
    int kthSmallest(TreeNode* root, int k) {
        //DFS but try to go only left when possible 
        vector<TreeNode*> path;
        dfs(root, path);
        return path[path.size() - k]->val;
    }
};
