class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        for(int i=0;i<pre.size();i++){
            int u=pre[i][0];
            int v=pre[i][1];
            adj[v].push_back(u);
        }
        vector<int>indeg(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++){
                indeg[adj[i][j]]++;
            }
        }
        queue<int>q;
        for(int i=0;i<indeg.size();i++){
            if(indeg[i]==0) q.push(i);
        }
        int c=0;
        while(!q.empty()){
            c++;
            int node=q.front();
            q.pop();
            for(int i=0;i<adj[node].size();i++){
                    indeg[adj[node][i]]--;
                    if(indeg[adj[node][i]]==0){
                        q.push(adj[node][i]);
                    }
            }
        }
        return c==n;
    }
};