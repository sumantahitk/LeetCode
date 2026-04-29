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
    int m1(TreeNode* root,int &ans){
        if(!root) return 0;
        return 1+max(m1(root->left,ans),m1(root->right,ans));
    }
    int maxDepth(TreeNode* root) {
        int ans=0;
       return  m1(root,ans);
        // return ans;
    }
};