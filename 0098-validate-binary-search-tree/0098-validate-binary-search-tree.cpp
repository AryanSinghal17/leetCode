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
  #include <climits>
class Solution {

public:
    bool helper(TreeNode* root,long left,long right){
        if(root == nullptr) return true;

        if(root->val <= left || root->val >= right) return false;

        bool lef = helper(root->left,left,root->val);
        bool rig = helper(root->right,root->val,right);

        return lef && rig;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,LONG_MIN,LONG_MAX);
    }
};