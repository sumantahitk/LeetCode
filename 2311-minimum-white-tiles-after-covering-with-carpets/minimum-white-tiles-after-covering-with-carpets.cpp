class Solution {
public:
    int find(int i,int k,string &s,int &cl,vector<vector<int>>&v){
        if(i>=s.size()) return 0;
        if(k==0){
            int cnt=0;
            for(int j=i;j<s.size();j++){
                if(s[j]=='1')cnt++;
            }
            return cnt;
        }
        if(v[i][k]!=-1) return v[i][k];
        int nottake=s[i]-'0'+find(i+1,k,s,cl,v);
        int take=find(i+cl,k-1,s,cl,v);
        return v[i][k]=min(nottake,take);
    }
    int minimumWhiteTiles(string s, int nc, int cl) { 
      int n=s.size();
      vector<vector<int>>v(n+1,vector<int>(nc+1,-1));
      return find(0,nc,s,cl,v);
    }
};