class Solution {
      int find(int i,int j,int [][]dp,int [][]grid){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0 || grid[i][j]==1) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        int left=find(i,j-1,dp,grid);
        int up=find(i-1,j,dp,grid);
        return dp[i][j]=up+left;
    }
    public int uniquePathsWithObstacles(int[][] grid) {
        int m=grid.length;
        int n=grid[0].length;
        if(grid[0][0]==1 || grid[m-1][n-1]==1) return 0;
        int [][]dp=new int[m][n];
        for(int []a:dp){
            Arrays.fill(a,-1);
        }
        return find(m-1,n-1,dp,grid);
    }
}