/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool rton(TreeNode* root,TreeNode* p,vector<TreeNode*>&ans){
        if(!root) return 0;
        ans.push_back(root);
        if(root->val==p->val){
            return 1;
        }
        int left=rton(root->left,p,ans);
        int right=rton(root->right,p,ans);

        if(left || right) return 1;
        else{
            ans.pop_back();
            return 0;
        }
    } 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>a,b;
        rton(root,p,a);
        rton(root,q,b);
        TreeNode* lca;
        int i=0,j=0;
        while(i<a.size() && j<b.size()){
            if(a[i]!=b[i]) return lca;
            lca=a[i];
            i++;
            j++;
        }
        return lca;
    }
};