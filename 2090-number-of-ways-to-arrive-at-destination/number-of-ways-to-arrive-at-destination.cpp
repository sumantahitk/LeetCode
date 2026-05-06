class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int src=0,dst=n-1;
        int mod=1e9+7;
        vector<vector<pair<int,int>>>adj(n);
        for(auto r:roads){
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }
       priority_queue< pair<long long,int>,vector< pair<long long,int>>,greater< pair<long long,int>>>q;
        q.push({0,0});
        vector<long long>dist(n,1e18);
        vector<long long>count(n,0);
        dist[0]=0;
        count[0]=1;
        while(!q.empty()){
            long long cost = q.top().first;
            int node = q.top().second;
            q.pop();
            if(dist[node]<cost) continue;
            for(int i=0;i<adj[node].size();i++){
                int nei=adj[node][i].first;
                int w=adj[node][i].second;
                if(dist[nei]>dist[node]+w){
                    dist[nei]=dist[node]+w;
                    count[nei]=count[node];
                    q.push({dist[nei], nei}); 
                }
                else if(dist[nei]==dist[node]+w){
                    count[nei]=(count[node]+count[nei])%mod;
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<count[i]<<" ";
        }
        return count[dst];
    }
};