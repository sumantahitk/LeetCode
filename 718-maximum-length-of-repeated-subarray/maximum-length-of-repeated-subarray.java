class Solution {
    int ans=0;
     int find(int n1,int n2,int[] s1,int[] s2,int [][]dp){
        if(n1==0||n2==0) return 0;
        if(dp[n1][n2]!=-1) return dp[n1][n2];

        if(s1[n1-1]==s2[n2-1]){
            dp[n1][n2]=1+find(n1-1,n2-1,s1,s2,dp);
            ans=Math.max(ans,dp[n1][n2]);
        }else{
            dp[n1][n2]=0;
        }
        return dp[n1][n2];
    }
    public int findLength(int[] s1, int[] s2) {
        int n1=s1.length;
        int n2=s2.length;
        int [][]dp=new int[n1+1][n2+1];
        for(int i=0;i<=n1;i++){
            Arrays.fill(dp[i],-1);
        }
        
         for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                find(i, j, s1, s2, dp);
            }
        }
        return ans;
    }
}