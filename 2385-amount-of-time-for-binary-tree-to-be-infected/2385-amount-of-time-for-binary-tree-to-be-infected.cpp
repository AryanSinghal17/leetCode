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
    void makegraph(unordered_map<int,vector<int>>&adj,int parent,TreeNode*curr){
        if(curr == nullptr) return;

        if(parent != -1){
            adj[curr->val].push_back(parent);
        }  
        if(curr->left){
            adj[curr->val].push_back(curr->left->val);
        }
        if(curr->right){
            adj[curr->val].push_back(curr->right->val);
        }

        makegraph(adj,curr->val,curr->left);
        makegraph(adj,curr->val,curr->right);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>>adj;
        makegraph(adj,-1,root);

        queue<int>q;
        unordered_set<int>visited;
        q.push(start);
        visited.insert(start);
        int min = 0;
        while(!q.empty()){
            int n = q.size();

            for(int i = 0;i<n;i++){
                int curr = q.front();
                q.pop();

                for(int &i: adj[curr]){
                    if(!visited.count(i))
                    q.push(i);
                    visited.insert(i);
                }
            }
            min++;
        }
        return min-1;
    }
};