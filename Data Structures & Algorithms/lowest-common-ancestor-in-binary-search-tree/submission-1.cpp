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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //if the curr is greater than the max, then we fuh
        //if the curr is less than the min, then we also fuh]
        // so we have the keep going until that and then keep the first node thats in between the two niodes
        int max = std::max(p->val, q->val);
        int min = std::min(p->val, q->val);
        auto* curr_node = root;
        while(true){
            //if the node is greater, go left
            if(curr_node->val > max){
                curr_node = curr_node->left;
            }
            //if the node is less than go right
            else if( curr_node->val  < min ){
                curr_node = curr_node->right;
            }else {
                return curr_node;
            }
        }
    }
};
