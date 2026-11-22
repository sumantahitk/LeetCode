class Solution {
    boolean find(int n,int tar,int[] nums,int [][]dp){
        if(tar==0) return true;
        if(n==0 ) return false;
        if(dp[n][tar]!=-1) return dp[n][tar]==1;
        boolean ans;
        if(tar>=nums[n-1]){
            ans=find(n-1,tar-nums[n-1],nums,dp) | find(n-1,tar,nums,dp);
        }
        else{
             ans=find(n-1,tar,nums,dp);
        }
         dp[n][tar]=ans?1:0;
         return ans;
    }
    public boolean canPartition(int[] nums) {
        int sum=0;
        for(int a:nums){
            sum+=a;
        }
        if(sum%2==1) return false;
        sum/=2;
        int n=nums.length;
        int [][]dp=new int[n+1][sum+1];
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],-1);
        }
        return find(n,sum,nums,dp);
    }
}