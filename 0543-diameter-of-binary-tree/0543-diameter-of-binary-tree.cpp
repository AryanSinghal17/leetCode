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
    int maxdepth(TreeNode*root){
        if(root == nullptr) return 0;
        else{
            return max(maxdepth(root->right),maxdepth(root->left))+1;
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        int leftDiameter = maxdepth(root->left);
        int rightDiameter = maxdepth(root->right);
        int opt1 = leftDiameter+rightDiameter;
        int opt2 = diameterOfBinaryTree(root->left);
        int opt3 = diameterOfBinaryTree(root->right);
        return max(opt1,max(opt2,opt3));
    }
};