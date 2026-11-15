class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>col(n,-1);
        queue<int>q;
        for(int i=0;i<n;i++){
           if(col[i]==-1){
             q.push(i);
            col[i]=0;
           while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int j=0;j<adj[node].size();j++){
                int nei=adj[node][j];
                if(col[nei]==-1){
                    col[nei]=(col[node]+1)%2;
                    q.push(nei);
                }
                else{
                    if(col[nei]==col[node]) return 0;
                }
            }
           }
           }
        }
        return 1;
    }
};