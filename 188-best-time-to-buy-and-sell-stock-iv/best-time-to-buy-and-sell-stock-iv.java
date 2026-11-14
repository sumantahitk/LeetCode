class Solution {
    int find(int buy,int n,int m,int k,int[] p,int [][][]dp){
        if(k==0 || n==m) return 0;
        if(dp[n][buy][k]!=-1) return dp[n][buy][k];
        if(buy==1){
            dp[n][buy][k]=Math.max(-p[n]+find(0,n+1,m,k,p,dp),find(1,n+1,m,k,p,dp));
        } else{
            dp[n][buy][k]=Math.max(p[n]+find(1,n+1,m,k-1,p,dp),find(0,n+1,m,k,p,dp));
        }
        return dp[n][buy][k];
    }
    public int maxProfit(int k, int[] p) {
         int n=p.length;
       int [][][]dp=new int[n+1][2][k+1];
       for(int [][]r:dp){
        for(int []a:r){
            Arrays.fill(a,-1);
        }
       }
        return find(1,0,n,k,p,dp);
    }
}