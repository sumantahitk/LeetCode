class Solution {
public:
    int minDistance(string s1, string s2) {
        
        int n=s1.size(),m=s2.size();
        // if(n==0 && m==0 ) return 0;
        
        vector<vector<int>>v(n+1,vector<int>(m+1,0));

        for(int i=0;i<n+1;i++){
           for(int j=0;j<m+1;j++){
            if(i==0) v[i][j]=j;
            if(j==0) v[i][j]=i;
           }
        }


        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1]){
                    v[i][j]=v[i-1][j-1];
                }else{
                    int in=v[i-1][j];
                    int de=v[i][j-1];
                    int re=v[i-1][j-1];
                    v[i][j]=1+min(min(in,de),re);
                }
            }
        }
        return v[n][m];
    }
};