class Solution {
public:
    int dfs(TreeNode* root, long long currSum, int target,
            unordered_map<long long, int>& mp) {
        if (!root) return 0;

        currSum += root->val;

        int count = mp[currSum - target];

        mp[currSum]++;

        count += dfs(root->left, currSum, target, mp);
        count += dfs(root->right, currSum, target, mp);

        mp[currSum]--; // backtrack

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> mp;
        mp[0] = 1;
        return dfs(root, 0, targetSum, mp);
    }
};