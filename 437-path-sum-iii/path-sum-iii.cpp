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
    int cnt=0;
    int find(TreeNode* root,int tar,long long sum,int &cnt){
        if(!root) return cnt;
        sum+=root->val;
        if(tar==sum){
            cnt++;
        }
        return find(root->left,tar,sum,cnt)+ find(root->right,tar,sum,cnt);
    }
    int pathSum(TreeNode* root, int tar) {
        if(!root) return 0;
        long long sum=0;
        int cnt=0;
        find(root,tar,sum,cnt);
        if(root->left)cnt+= pathSum(root->left,tar);
        if(root->right) cnt+=pathSum(root->right,tar);
        return cnt;
    }
};