class Solution {

    int find(int n1,int n2,String s1,String s2,int [][]dp){
        if(n1==0||n2==0) return 0;
        if(dp[n1][n2]!=-1) return dp[n1][n2];

        if(s1.charAt(n1-1)==s2.charAt(n2-1)){
            dp[n1][n2]=1+find(n1-1,n2-1,s1,s2,dp);
        }else{
            dp[n1][n2]=Math.max(find(n1,n2-1,s1,s2,dp),find(n1-1,n2,s1,s2,dp));
        }
        return dp[n1][n2];
    }
    public int longestCommonSubsequence(String s1, String s2) {
        int n1=s1.length();
        int n2=s2.length();
        int [][]dp=new int[n1+1][n2+1];
        for(int i=0;i<=n1;i++){
            Arrays.fill(dp[i],-1);
        }
        return find(n1,n2,s1,s2,dp);
    }
}