class Solution {
    int find(int i,int j,int [][]dp,int [][]grid){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return Integer.MAX_VALUE;
        if(dp[i][j]!=-1) return dp[i][j];
        int left=find(i,j-1,dp,grid);
        int up=find(i-1,j,dp,grid);
        return dp[i][j]=Math.min(up,left)+grid[i][j];
    }
    public int minPathSum(int[][] grid) {
         int m=grid.length;
        int n=grid[0].length;
         int [][]dp=new int[m][n];
        for(int []a:dp){
            Arrays.fill(a,-1);
        }
        return find(m-1,n-1,dp,grid);
    }
}