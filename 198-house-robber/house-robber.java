class Solution {
     int find(int i,int[]dp,int[] h){
        if(i==0) return h[0];
        if(i==1) return Math.max(h[0],h[1]);
        if(dp[i]!=-1)return dp[i];
        int take=find(i-2,dp,h)+h[i];
        int nottake=find(i-1,dp,h);
        return dp[i]=Math.max(take,nottake);
    }
    public int rob(int[] h) {
         int n=h.length;
        int[]dp=new int[n+1];
        Arrays.fill(dp,-1);
        return find(n-1,dp,h);
    }
}