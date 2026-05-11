class Solution {
public: 
      int find(int i,int buy,int k,int n,vector<int>&p,vector<vector<vector<int>>>&v){
        if(i==n || k==0) return 0;
        if(v[i][buy][k]!=-1) return v[i][buy][k];

        if(buy){
            v[i][buy][k]=max(-p[i]+find(i+1,0,k,n,p,v),0+find(i+1,1,k,n,p,v));
        }else{
            v[i][buy][k]=max(p[i]+find(i+1,1,k-1,n,p,v),0+find(i+1,0,k,n,p,v));
        }
        return v[i][buy][k];
    }
    int maxProfit(vector<int>& p) {
         int i=0,n=p.size(),k=2;
        vector<vector<vector<int>>> v(n+1,vector<vector<int>>(2, vector<int>(k + 1, -1)));
         return find(0,1,k,n,p,v);
    }
};