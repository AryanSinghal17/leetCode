/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        if (!root)
            return vec;

        stack<TreeNode*> ans;
        ans.push(root);

        while (!ans.empty()) {
            auto top = ans.top();
            ans.pop();
            vec.push_back(top->val);

            if(top->right)ans.push(top->right);
            if(top->left)ans.push(top->left);
        }
        return vec;
    }
};