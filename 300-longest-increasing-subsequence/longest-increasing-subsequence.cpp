class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int mx=0;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
            }
            if(mx<dp[i]){
                mx=dp[i];
            }
        }
        return mx;
    }
};