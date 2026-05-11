class Solution {
public:
      int find(int i,int buy,int n,vector<int>&p,vector<vector<int>>&v){
        if(i>=n) return 0;
        if(v[i][buy]!=-1) return v[i][buy];

        if(buy){
            v[i][buy]=max(-p[i]+find(i+1,0,n,p,v),0+find(i+1,1,n,p,v));
        }else{
            v[i][buy]=max(p[i]+find(i+2,1,n,p,v),0+find(i+1,0,n,p,v));
        }
        return v[i][buy];
    }
    int maxProfit(vector<int>& p) {
         int i=0,n=p.size();
        vector<vector<int>>v(n+1,vector<int>(2,-1));
        return find(0,1,n,p,v);
    }
};