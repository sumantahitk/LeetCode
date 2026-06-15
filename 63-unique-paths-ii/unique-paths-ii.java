class Solution {
    public int uniquePathsWithObstacles(int[][] grid) {
        
        int n=grid.length;
        int m=grid[0].length;
        if(grid[0][0]==1 || grid[n-1][m-1]==1) return 0;
        if(n==1 && m==1) {
            if(grid[0][0]==1 || grid[n-1][m-1]==1) return 0;
            else return 1;
        }
          int[][]dp=new int[n][m];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],0);
        }
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) continue;
                if(grid[i][j]==1) {
                    dp[i][j]=0;
                    continue;
                }
                int left=0,right=0;
                if(i>0)left=dp[i-1][j];
                if(j>0) right=dp[i][j-1];
                dp[i][j]=left+right;
            }
        }
        return dp[n-1][m-1];
    
    }
}