class Solution {
    int find(int i,int j,ArrayList<Integer>arr,int[][] dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mx=0;
        for(int k=i;k<=j;k++){
            int cost=find(i,k-1,arr,dp)+find(k+1,j,arr,dp)+arr.get(i-1)*arr.get(k)*arr.get(j+1);
            mx=Math.max(cost,mx);
        }
        return dp[i][j]=mx;
    }
    public int maxCoins(int[] nums) {
        int n=nums.length;
        ArrayList<Integer>arr=new ArrayList<>();
        arr.add(1);
        for(int a:nums){
            arr.add(a);
        }
        arr.add(1);
        int [][]dp=new int[n+2][n+2];
        for(int []r:dp){
            Arrays.fill(r,-1);
        }
        return find(1,n,arr,dp);
    }
}