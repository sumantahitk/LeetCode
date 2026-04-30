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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        stack<TreeNode*>s1,s2;
        s1.push(root);
        vector<vector<int>>ans;
        while(!s1.empty() || !s2.empty()){
            vector<int>a;
            while(!s1.empty()){
                TreeNode* node=s1.top();
                s1.pop();
                a.push_back(node->val);
                 if(node->left) s2.push(node->left);
                if(node->right)s2.push(node->right);
               
            }
            ans.push_back(a);
            vector<int>b;
            while(!s2.empty()){
                TreeNode* node=s2.top();
                s2.pop();
                b.push_back(node->val);
                if(node->right) s1.push(node->right);
                if(node->left)s1.push(node->left);
               
            }
            if(!b.empty())
            ans.push_back(b);
        }
        // ans.pop_back();
        return ans;

    }
};