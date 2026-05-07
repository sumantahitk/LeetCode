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
    bool find(TreeNode* root, int tar,int sum) {
        if(!root) return 0;
        sum+=root->val;
        if(!root->left && !root->right){
            if(sum==tar)
            return 1;
            
        }
        
        int l=find(root->left,tar,sum);
        int r=find(root->right,tar,sum);
        if(l||r){
            return 1;
        }else{
            sum-=root->val;
            return 0;
        }
    }
    bool hasPathSum(TreeNode* root, int tar) {
        int sum=0;
        return find(root,tar,sum);
        // return 0;
    }
};