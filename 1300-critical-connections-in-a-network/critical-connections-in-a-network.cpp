class Solution {
public:
    void dfs(int node,int par,vector<vector<int>>&adj,vector<vector<int>>&ans,vector<int>&disc,vector<int>&low,vector<bool>&visited,int &timer){
        disc[node]=low[node]=timer;
        visited[node]=1;
        for(int i=0;i<adj[node].size();i++){
            int nei=adj[node][i];
            if(par==nei) continue;
            if(visited[nei]){
                low[node]=min(low[node],low[nei]);
            }
            else{
                timer++;
                dfs(nei,node,adj,ans,disc,low,visited,timer);

                if(disc[node]<low[nei]){
                    ans.push_back({node,nei});
                }
                low[node]=min(low[node],low[nei]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        vector<vector<int>>ans;
        vector<vector<int>>adj(n);
        for(int i=0;i<con.size();i++){
            int u=con[i][0];
            int v=con[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,0);
        vector<int>disc(n,0);
        vector<int>low(n,0);
        int timer=0;
        dfs(0,-1,adj,ans,disc,low,visited,timer);
        return ans;
    }
};