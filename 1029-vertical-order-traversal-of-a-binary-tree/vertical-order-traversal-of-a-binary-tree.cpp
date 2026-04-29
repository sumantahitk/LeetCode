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
    void find(TreeNode* root,int &l,int &h,int pos){
        if(!root) return;
        l=min(l,pos);
        h=max(h,pos);
        find(root->left,l,h,pos-1) ;
        find(root->right,l,h,pos+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int l=0,r=0,p=0;
        find(root,l,r,p);

        vector<vector<pair<int,int>>>pos(r+1);
        vector<vector<pair<int,int>>>neg(abs(l));
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            TreeNode* node=temp.first;
            int row=temp.second.first;
            int col=temp.second.second;
            if(col>=0){
                pos[col].push_back({row,node->val});
            }else{
                neg[abs(col)-1].push_back({row,node->val});
            }
            if(node->left){
                q.push({node->left,{row+1,col-1}});
            }
            if(node->right){
                q.push({node->right,{row+1,col+1}});
            }
        }
        vector<vector<int>>ans;
        for(int i=neg.size()-1;i>=0;i--){
            vector<int>a;
            sort(neg[i].begin(),neg[i].end());
            for(int j=0;j<neg[i].size();j++){
                a.push_back(neg[i][j].second);
            }
            ans.push_back(a);
        }
        for(int i=0;i<pos.size();i++){
            vector<int>a;
            sort(pos[i].begin(),pos[i].end());
            for(int j=0;j<pos[i].size();j++){
                a.push_back(pos[i][j].second);
            }
            ans.push_back(a);
        }
        return ans;
    }
};