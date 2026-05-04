class Solution {
public:
    bool m1(vector<vector<int>>& g) {
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
    bool dfs(int node,vector<int>&col,vector<vector<int>>&g){
        
        for(int i=0;i<g[node].size();i++){
            if(col[g[node][i]]==-1){
                col[g[node][i]]=!col[node];
                 if (!dfs(g[node][i], col, g)) return false;
            }
           
            else if(col[node]==col[g[node][i]]) return 0;
        }
        return 1;
    }
    bool m2(vector<vector<int>>& g) {
        int n=g.size();
        vector<int>col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                col[i]=1;
                if(!dfs(i,col,g))return 0;
            }
        }
        return 1;
    }
     bool isBipartite(vector<vector<int>>& g) {
       
       return m2(g);
         
    }
};