class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succ, int st, int end) {
        priority_queue<pair<double,int>>pq;
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double p=succ[i];
            adj[u].push_back({v,p});
            adj[v].push_back({u,p});
        }
        double ans=0;
        vector<double> prob(n, 0.0);
        pq.push({1.0,st});
        prob[st]=1.0;
        while(!pq.empty()){
            int node=pq.top().second;
            double pob=pq.top().first;
            pq.pop();
            if(node==end)
                {
                    return pob;
                }
            for(int i=0;i<adj[node].size();i++){
                int nei=adj[node][i].first;
                double p=adj[node][i].second;
                double currpob=p*pob;
                if(currpob>prob[nei]){
                    prob[nei]=currpob;
                    pq.push({currpob,nei});
                }
            }
        }
        return 0.0;
    }
};