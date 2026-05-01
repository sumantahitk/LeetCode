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
    void find(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&mp){
        if(!root) return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                mp[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right]=node;
                q.push(node->right);
            }
        }
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>mp;
        find(root,mp);
        int count=0;
        queue<TreeNode*>q;
        q.push(target);
        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;
        while(!q.empty()){
           int n=q.size();
            if(count==k) break;
            count++;

            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                visited[node->left]=true;
                q.push(node->left);
            }
            if(node->right && !visited[node->right]){
                visited[node->right]=true;
                q.push(node->right);
            }
            if(mp[node] && !visited[mp[node]]){
                visited[mp[node]]=true;
                q.push(mp[node]);
            }
            }
            
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};