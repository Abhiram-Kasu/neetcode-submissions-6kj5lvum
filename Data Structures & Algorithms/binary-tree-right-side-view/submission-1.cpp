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
    vector<int> rightSideView(TreeNode* root) {
        //bfs type thing
        std::vector<int> res{};
        std::queue<TreeNode*> q{};

        if(not root){
            return res;
        }
        q.push(root);
        while(not q.empty()){
            //get all the children of this level and then push the last one to res;
            res.push_back(q.back()->val);
            //get all children and then push them back onto the res;
            decltype(q) temp{};
            while(not q.empty()){
                auto node = q.front();
                q.pop();
                if(node->left){
                    temp.push(node->left);
                }
                if(node->right){
                    temp.push(node->right);
                }
            }

            q = std::move(temp);


        }

        return res;
    }
};
