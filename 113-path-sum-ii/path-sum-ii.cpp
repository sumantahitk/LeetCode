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
bool find(TreeNode* root, int tar,int sum,vector<vector<int>>&ans ,vector<int>&a) {
        if(!root) return 0;
        sum+=root->val;
        a.push_back(root->val);
        if(!root->left && !root->right){
            if(sum==tar)
            {
                ans.push_back(a);
                a.pop_back();
                return 1;
                
            }
            // return 0;
            
            
        }
        
        int l=find(root->left,tar,sum,ans,a);
        int r=find(root->right,tar,sum,ans,a);
        if(l||r){
            a.pop_back();
            return 1;
        }else{
            sum-=root->val;
            a.pop_back();
            return 0;
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>a;
        find(root,targetSum,0,ans,a);
        return ans;
    }
};