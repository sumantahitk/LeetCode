class Solution {
    int find(int i,int j,ArrayList<Integer>arr,int[][] dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mn=Integer.MAX_VALUE;
        for(int k=i;k<=j;k++){
            int cost=find(i,k-1,arr,dp)+find(k+1,j,arr,dp)+(arr.get(j+1)-arr.get(i-1));
            mn=Math.min(cost,mn);
        }
        return dp[i][j]=mn;
    }
    public int minCost(int m, int[] cuts) {
          int n=cuts.length;
          Arrays.sort(cuts);
        ArrayList<Integer>arr=new ArrayList<>();
        arr.add(0);
        for(int a:cuts){
            arr.add(a);
        }
        arr.add(m);
        int [][]dp=new int[n+2][n+2];
        for(int []r:dp){
            Arrays.fill(r,-1);
        }
        return find(1,n,arr,dp);
    }
}