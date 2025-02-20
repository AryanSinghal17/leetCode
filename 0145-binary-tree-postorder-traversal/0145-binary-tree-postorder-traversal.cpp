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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
         if (root == nullptr) return ans;
        stack<TreeNode*>sleft,sright;
        sleft.push(root);
        while(!sleft.empty()){
            TreeNode*num = sleft.top();
            sleft.pop();
            sright.push(num);
            
            if(num->left) sleft.push(num->left);
            if(num->right) sleft.push(num->right);
        }

        while(!sright.empty()){
            ans.push_back(sright.top()->val);
            sright.pop();
        }
        
        return ans;
    }
};