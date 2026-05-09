class Solution {
public:
    int m1(int i,int j,string &s1,string &s2,vector<vector<int>>&v){
        if(i<=0 || j<=0) return 0;
        if(v[i][j]!=-1) return v[i][j];
        if(s1[i-1]==s2[j-1]){
            v[i][j]=1+m1(i-1,j-1,s1,s2,v);
        }else{
            v[i][j]=max(m1(i-1,j,s1,s2,v),m1(i,j-1,s1,s2,v));
        }
        return v[i][j];
        
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>>v(n+1,vector<int>(m+1,-1));

        int i=n,j=m;
        return m1(i,j,s1,s2,v);
    }
};