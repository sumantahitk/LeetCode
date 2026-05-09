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
    int m2(string &s1,string &s2){
         int n=s1.size(),m=s2.size();
        vector<vector<int>>v(n+1,vector<int>(m+1,0));
        int i=0,j=0;
       for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(s1[i-1]==s2[j-1]){
                v[i][j]=1+v[i-1][j-1];
            }
            else{
                v[i][j]=max(v[i-1][j],v[i][j-1]);
            }
        }
       }

        return v[n][m];
    }
     int m3(string &s1,string &s2){
         int n=s1.size(),m=s2.size();
        vector<int>prev(m+1,0),curr(m+1,0);
        int i=0,j=0;
       for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(s1[i-1]==s2[j-1]){
                curr[j]=1+prev[j-1];
            }
            else{
                curr[j]=max(prev[j],curr[j-1]);
            }
        }
        prev=curr;
       }

        return prev[m];
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<vector<int>>v(n+1,vector<int>(m+1,-1));

        int i=n,j=m;
        // return m1(i,j,s1,s2,v);

        return m3(s1,s2);
    }
};