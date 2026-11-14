class Solution {
    int find(int buy,int n,int m,int[] p,int [][]dp){
        if(n==m) return 0;
        if(dp[n][buy]!=-1) return dp[n][buy];
        if(buy==1){
            dp[n][buy]=Math.max(-p[n]+find(0,n+1,m,p,dp),find(1,n+1,m,p,dp));
        } else{
            dp[n][buy]=Math.max(p[n]+find(1,n+1,m,p,dp),find(0,n+1,m,p,dp));
        }
        return dp[n][buy];
    }
    public int maxProfit(int[] p) {
        int n=p.length;
       int [][]dp=new int[n+1][2];
       for(int []r:dp){
        Arrays.fill(r,-1);
       }
        return find(1,0,n,p,dp);
    }
}