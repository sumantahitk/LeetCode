class Solution {
public:
    int row[4] = {-1, 0, 1, 0};
    int col[4] = {0, 1, 0, -1};
    bool verify(int i,int j,int n,int m){
        return (i>=0 && j>=0 && i<n && j<m);
    }
    int minimumEffortPath(vector<vector<int>>& grid) {
         int n=grid.size(),m=grid[0].size();
       

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int cost=pq.top().first;
            int u=pq.top().second.first;
            int v=pq.top().second.second;
            pq.pop();
            if(cost > dist[u][v]) continue;
            if(u==n-1 && v==m-1){
                return cost;
            }
            for(int k=0;k<4;k++){
                int newi=u+row[k];
                int newj=v+col[k];
                if(verify(newi,newj,n,m)){
                    int w=grid[newi][newj];
                    int diff=max(abs(w-grid[u][v]),cost);
                    if(dist[newi][newj]>diff){
                    dist[newi][newj]=diff;
                    pq.push({dist[newi][newj],{newi,newj}});
                    }
                }
            }
        }
        return -1;
    }
};