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
int m1(TreeNode* root){
        if(!root) return 0;
        return 1+max(m1(root->left),m1(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return 1;
        int left=m1(root->left);
        int right=m1(root->right);
        cout<<left<<" "<<right<<endl;
        if(abs(left-right)>1){
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
};