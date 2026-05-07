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
      bool m1(TreeNode* root, int targetSum) {
       return find(root,targetSum,0);
    }
      bool m2(TreeNode* root, int targetSum) {
        if (!root) return false;

        // If leaf node, check remaining sum
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }

        // Reduce target and recurse
        return m2(root->left, targetSum - root->val) ||
               m2(root->right, targetSum - root->val);
    }
    bool hasPathSum(TreeNode* root, int tar) {
       return m2(root,tar);
    }
};