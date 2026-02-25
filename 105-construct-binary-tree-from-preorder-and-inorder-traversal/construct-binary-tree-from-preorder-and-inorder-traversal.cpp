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
int find(vector<int>&in,int tar,int st,int end){
    for(int i=st;i<=end;i++){
        if(in[i]==tar){
            return i;
        }
    }
    return -1;
}
    TreeNode* tree(vector<int>&pre,vector<int>&in,int idx,int st,int end){
        if(st>end) return NULL;
        TreeNode* root=new TreeNode(pre[idx]);
        int pos=find(in,pre[idx],st,end);
        root->left=tree(pre,in,idx+1,st,pos-1);
        root->right=tree(pre,in,idx+(pos-st)+1,pos+1,end);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int idx=0;
        return tree(pre,in,idx,0,pre.size()-1);
    }
};