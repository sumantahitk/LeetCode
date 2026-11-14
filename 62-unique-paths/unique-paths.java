class Solution {
     int row[]={-1,0,+1,0};
    int col[]={0,+1,0,-1};
    boolean chck(int i,int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int find(int i,int j,int [][]dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int left=find(i,j-1,dp);
        int up=find(i-1,j,dp);
        return dp[i][j]=up+left;
    }
    public int uniquePaths(int m, int n) {
        
        int [][]dp=new int[m][n];
        for(int []a:dp){
            Arrays.fill(a,-1);
        }
        return find(m-1,n-1,dp);
    }
}