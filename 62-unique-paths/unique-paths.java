class Solution {
    int row[]={-1,0,+1,0};
    int col[]={0,+1,0,-1};
    boolean chck(int i,int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    public int uniquePaths(int n, int m) {
        int[][]dp=new int[n][m];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],0);
        }
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) continue;
                int left=0,right=0;
                if(i>0)left=dp[i-1][j];
                if(j>0) right=dp[i][j-1];
                dp[i][j]=left+right;
            }
        }
        return dp[n-1][m-1];
    }
}