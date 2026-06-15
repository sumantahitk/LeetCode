class Solution {
    int find(int n,int amt,int[]c,int [][]dp){
        if(n==0) return Integer.MAX_VALUE-1;
        if(amt==0) return 0;
        if(dp[n][amt]!=-1) return dp[n][amt];

        if(amt>=c[n-1]){
            dp[n][amt]=Math.min(find(n,amt-c[n-1],c,dp)+1,find(n-1,amt,c,dp));
        }else{
            dp[n][amt]=find(n-1,amt,c,dp);
        }
        return dp[n][amt];
    }
    public int coinChange(int[] c, int amt) {
        int n=c.length;
        int[][] dp=new int[n+1][amt+1];
          for(int i = 0;i <= n; i++) {
            Arrays.fill(dp[i], -1);
        }

        int ans=find(n,amt,c,dp);
    return ans==Integer.MAX_VALUE-1?-1:ans;
    }
}