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
    vector<int> find(TreeNode* root,int x){
        int f=-1,c=-1;
        TreeNode *temp=root;
        while(root){
            if(root->val<=x){
                f=root->val;
                root=root->right;
            }else{
                root=root->left;
            }
        }
         while(temp){
            if(temp->val>=x){
                c=temp->val;
                temp=temp->left;
            }else{
                temp=temp->right;
            }
        }
        return {f,c};
    }

    void in(TreeNode* root,vector<int>&arr){
        if(!root) return;
        in(root->left,arr);
        arr.push_back(root->val);
        in(root->right,arr);
    }
     vector<vector<int>> m1(TreeNode* root, vector<int>& q) {
        vector<vector<int>> ans;
        for(int i=0;i<q.size();i++){
            ans.push_back(find(root,q[i]));
        }
        return ans;
    }
    vector<int>binary(vector<int>&arr,int x){
        int f=-1,c=-1,n=arr.size();
        int l=0,r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]<=x){
                f=arr[mid];
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        l=0,r=n-1;
         while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]>=x){
                c=arr[mid];
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return {f,c};
    }
     vector<vector<int>> m2(TreeNode* root, vector<int>& q) {
        vector<int>arr;
        in(root,arr);
        vector<vector<int>> ans;
        for(int i=0;i<q.size();i++){
            ans.push_back(binary(arr,q[i]));
        }
        return ans;
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& q) {
       return m2(root,q);
    }
};