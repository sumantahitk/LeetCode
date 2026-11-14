class Solution {
    boolean find(int n,int sum,int [][] dp,int []arr){
        if(sum==0) return true;
        if(n==0) return false;
        if(dp[n][sum]!=-1) return dp[n][sum]==1;
        boolean ans;
        if(sum>=arr[n-1]){
            ans=find(n-1,sum-arr[n-1],dp,arr) || find(n-1,sum,dp,arr);
        }
        else{
            ans=find(n-1,sum,dp,arr);
        }
         dp[n][sum]=ans?1:0;
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
        for(int []r:dp){
            Arrays.fill(r,-1);
        }
        return find(n,sum,dp,nums);
    }
}