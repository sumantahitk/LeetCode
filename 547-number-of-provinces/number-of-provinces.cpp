class Solution {
public:
void dfs(int i,vector<bool>&vis,vector<vector<int>>&adj){
    vis[i]=1;

    for(int j=0;j<adj[i].size();j++){
        if(!vis[adj[i][j]]){
            dfs(adj[i][j],vis,adj);
        }
    }
}
    int findCircleNum(vector<vector<int>>& arr) {
        int n=arr.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && arr[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++){
               cout<<i<<" "<<adj[i][j]<<endl;
            }
            // cout<<endl;
        }
        int c=0;
        vector<bool>vis(n,0);
        for(int i=0;i<adj.size();i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                c++;
            }
        }
        return c;
    }
};