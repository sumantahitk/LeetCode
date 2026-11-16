class Solution {
    public int lengthOfLIS(int[] nums) {
        int n=nums.length,mx=Integer.MIN_VALUE;
        int[] dp=new int[n];
        Arrays.fill(dp,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
            mx=Math.max(mx,dp[i]);
        }
        return mx;
    }
}