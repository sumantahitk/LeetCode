class Solution {
     int find(int i,int[]dp,int[] h){
        if(i==0) return h[0];
        if(i==1) return Math.max(h[0],h[1]);
        if(dp[i]!=-1)return dp[i];
        int take=find(i-2,dp,h)+h[i];
        int nottake=find(i-1,dp,h);
        return dp[i]=Math.max(take,nottake);
    }
    public int rob(int[] nums) {
        
        int n=nums.length;
        if(n==1) return nums[0];
        if(n==2) return Math.max(nums[0],nums[1]);
        int a[]=new int[n-1];
        int b[]=new int[n-1];
        int dp1[]=new int[n+1];
        int dp2[]=new int[n+1];
        Arrays.fill(dp1,-1);
        Arrays.fill(dp2,-1);
        int j=0,k=0;
        for(int i=0;i<n;i++){
            if(i!=n-1){
                a[j++]=nums[i];
            }
            if(i!=0){
                b[k++]=nums[i];
            }
        }
        return Math.max(find(n-2,dp1,a),find(n-2,dp2,b));
    }
}