class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto e:times)
        {
            adj[e[0]-1].push_back({e[1]-1,e[2]});
        }
        
        queue<pair<int,int>>q;
        q.push({k-1,0});
        vector<int>dist(n,INT_MAX);
        dist[k-1]=0;
        while(!q.empty()){
            int node=q.front().first;
            int wt=q.front().second;
            q.pop();
            for(int i=0;i<adj[node].size();i++){
                int nei=adj[node][i].first;
                int w=adj[node][i].second;
                if(dist[nei]>dist[node]+w){
                    dist[nei]=dist[node]+w;
                    q.push({nei,w});
                }
            }
        }
        int ans=0;
         for(int i=0;i<n;i++){
            if(dist[i]==INT_MAX) return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};