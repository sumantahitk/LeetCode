class Solution {
    int find(int i,int[]dp,HashSet<String>st,String s){
        if(i==s.length()) return 1;
        if(dp[i]!=-1) return dp[i];

        StringBuilder temp=new StringBuilder();

        for(int j=i;j<s.length();j++){
            temp.append(s.charAt(j));
            if(st.contains(temp.toString())){
                if(find(j+1,dp,st,s)==1){
                    return dp[i]=1;
                }
            }
        }
        return dp[i]=0;
    }
    public boolean wordBreak(String s, List<String> w) {
        int n=s.length();
       int []dp=new int[n];
        HashSet<String>st=new HashSet<>(w);
        Arrays.fill(dp,-1);

        return find(0,dp,st,s)==1;
    }
}