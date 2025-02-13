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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == nullptr) return ans;
        stack<TreeNode*>st;
        st.push(root);

        while(!st.empty()){
            TreeNode* value = st.top();
            st.pop();
            ans.push_back(value->val);

            if(value->right){
                st.push(value->right);
            }
            if(value->left){
                st.push(value->left);
            }
        }
        return ans;
    }
};