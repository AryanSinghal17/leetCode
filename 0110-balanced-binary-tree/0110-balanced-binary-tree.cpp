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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        else{
            return max(maxDepth(root->right),maxDepth(root->left))+1;
        }
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int left_Hight = maxDepth(root->left);
        int right_Hight = maxDepth(root->right);

        int diff = abs(left_Hight - right_Hight);

        return diff<=1 && isBalanced(root->left) && isBalanced(root->right);
     }
};