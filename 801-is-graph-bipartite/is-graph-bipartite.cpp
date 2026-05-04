class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        int n=g.size();
        queue<int>q;
        
        vector<int>col(n,-1);
        for(int i=0;i<g.size();i++){
            if(col[i]==-1){
                col[i]=1;
                q.push(i);
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(int j=0;j<g[node].size();j++){
                        if(col[g[node][j]]==-1){
                            col[g[node][j]]=(col[node]+1)%2;
                            q.push(g[node][j]);
                        }else{
                            if(col[node]==col[g[node][j]]) return 0;
                        }

                    }
                }
            }
        }
        return 1;
    }
};