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
    TreeNode*mirror(TreeNode*root){
        if(root == nullptr) return root;

        TreeNode* temp = new TreeNode(root->val);
        
        temp->left = mirror(root->right);
        temp->right = mirror(root->left);
        return temp;
    }
    bool isIdentical(TreeNode*root,TreeNode*node){
        if (root == nullptr && node == nullptr) return true;
        if (root == nullptr || node == nullptr) return false;

        return (root->val == node->val) && isIdentical(root->left ,node->left) && isIdentical(root->right,node->right);
    }
    bool isSymmetric(TreeNode* root) {
        
        if (root == nullptr) return true;

        TreeNode*node = mirror(root);
        
        return isIdentical(root, node);

    }
};