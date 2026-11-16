class Solution {
    boolean verify(String a , String b){
        if(a.length()!=1+b.length()) return false;
        int i=a.length()-1,j=b.length()-1;
        while(i>=0){
            if(j>=0 && a.charAt(i)==b.charAt(j)){
                i--;
                j--;
            }else{
                i--;
            }
        }
        return j==-1 ?true:false;

    }
    public int longestStrChain(String[] words) {
        Arrays.sort(words,(a,b)->a.length()-b.length());
         int n=words.length,mx=Integer.MIN_VALUE;
        int[] dp=new int[n];
        Arrays.fill(dp,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(verify(words[i],words[j]) && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
            mx=Math.max(mx,dp[i]);
        }
        return mx;
    }
}