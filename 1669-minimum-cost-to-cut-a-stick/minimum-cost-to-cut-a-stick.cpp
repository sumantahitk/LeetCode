class Solution {
public:
    int find(int i,int j,vector<int>&arr, vector<vector<int>>&v){
        if(i>j)return 0;
        if(v[i][j]!=-1) return v[i][j];

        int mn=INT_MAX;
        for(int k=i;k<=j;k++){
            int ans=find(i,k-1,arr,v)+find(k+1,j,arr,v)+arr[j+1]-arr[i-1];
            mn=min(mn,ans);
        }
        return v[i][j]=mn;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        int m=cuts.size();
        vector<vector<int>>v(m,vector<int>(m,-1));
        return find(1,m-2,cuts,v);
    }
};