class Solution {
public:
    bool find(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0) return 1;
        if(j==0) return 0;
        if(i==0){
            for(int k=0;k<j;k++){
                if(s2[k]!='*') return 0;
            }
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i-1]==s2[j-1] || s2[j-1]=='?'){
           return dp[i][j]=find(s1,s2,i-1,j-1,dp);
        }
        else if(s2[j-1]=='*'){
           return dp[i][j]=find(s1,s2,i,j-1,dp) || find(s1,s2,i-1,j,dp);
        }
        return dp[i][j]=0;
    }
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return find(s,p,n,m,dp);
    }
};