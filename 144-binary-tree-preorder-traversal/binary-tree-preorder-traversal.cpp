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
        void m1(TreeNode* root,vector<int>&ans) {
        if(!root) return ;
        ans.push_back(root->val);
        m1(root->left,ans);
        m1(root->right,ans);
    }
    void m2(TreeNode* root,vector<int>&ans) {
        if(!root) return ;
       stack<TreeNode*>st;
       st.push(root);
       while(!st.empty()){
            TreeNode* node=st.top();
            ans.push_back(st.top()->val);
            st.pop();
            if(node->right){
                st.push(node->right);
            }
            if(node->left){
                st.push(node->left);
            }
       }
       return ;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        m2(root,ans);
        return ans;
    }
};