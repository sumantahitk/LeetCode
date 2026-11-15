class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto a:f){
            adj[a[0]].push_back({a[1],a[2]});
        }
     queue<pair<int,pair<int,int>>>q;

        q.push({0,{0,src}});
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        while(!q.empty()){
            int cost=q.front().first;
            int step=q.front().second.first;
            int node=q.front().second.second;

            q.pop();
            if(step>k) continue;
           
            for(int i=0;i<adj[node].size();i++){
                int nei=adj[node][i].first;
                int wt=adj[node][i].second;
                if(cost+wt<dist[nei]){
                    dist[nei]=cost+wt;
                    q.push({dist[nei],{step+1,nei}});
                }
            }
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};