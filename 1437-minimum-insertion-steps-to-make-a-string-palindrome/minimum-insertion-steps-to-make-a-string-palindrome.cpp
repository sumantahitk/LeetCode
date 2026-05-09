class Solution {
public:
 int find1(string s1,string s2,int n ,int m){
          vector<vector<int>>dp(n+1,vector<int>(m+1,0));
          for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
          }
          return dp[n][m];
    }
    int minInsertions(string s) {
         string s1=s,s2=s;
        reverse(s1.begin(),s1.end());
        int n=s.size();
        int lps= find1(s1,s2,n,n);
        return n-lps;
    }
};