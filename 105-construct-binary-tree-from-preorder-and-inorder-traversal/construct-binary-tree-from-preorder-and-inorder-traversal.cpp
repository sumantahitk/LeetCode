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
    int find(int tar,vector<int>arr,int st,int end){
        for(int i=st;i<=end;i++){
            if(arr[i]==tar) return i;
        }
        return 0;
    }
    TreeNode* build(vector<int>& pre, vector<int>& in,int idx,int st,int end){
        if(st>end) return NULL;
        TreeNode* root=new TreeNode(pre[idx]);
        int pos =find(pre[idx],in,st,end);
        root->left=build(pre,in,idx+1,st,pos-1);
        root->right=build(pre,in,idx+(pos-st)+1,pos+1,end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,inorder,0,0,preorder.size()-1);
    }
};