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
    void find(TreeNode* root,vector<string>&ans,vector<int>&a){
        if(!root) return;
        a.push_back(root->val);
        if(!root->left && !root->right){
            string temp="";
            for(int i=0;i<a.size();i++){
                 temp += to_string(a[i]);   // ✅ FIX
                if(i != a.size() - 1) temp += "->";
            }
           
            ans.push_back(temp);
        }
       else{
         find(root->left,ans,a);
         find(root->right,ans,a);
       }
       a.pop_back();
       
    }
    vector<string> binaryTreePaths(TreeNode* root) {
         vector<string>ans;
        vector<int>a;
        find(root,ans,a);
        return ans;
    }
};