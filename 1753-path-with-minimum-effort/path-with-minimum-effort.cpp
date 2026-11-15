class Solution {
public:
    int row[4] = {-1, 0, 1, 0};
    int col[4] = {0, 1, 0, -1};
    bool verify(int i,int j,int n,int m){
        return (i>=0 && j>=0 && i<n && j<m);
    }
    int minimumEffortPath(vector<vector<int>>& grid) {
          int n=grid.size();
        int m=grid[0].size();
       

       
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
       vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        q.push({0,{0,0}});
        dist[0][0]=0;
        while(!q.empty()){
            int cost=q.top().first;
            int i=q.top().second.first;
            int j=q.top().second.second;
            q.pop();
            
            if(dist[i][j]<cost)continue;

            if(i==n-1 && j==m-1) return cost;
            for(int k=0;k<4;k++){
                int newi=row[k]+i;
                int newj=col[k]+j;
                if(verify(newi,newj,n,m)){
                    int cal=abs(grid[newi][newj]-grid[i][j]);
                        int mx=max(cost,cal);
                        if(dist[newi][newj]>mx){
                            dist[newi][newj]=mx;
                            q.push({mx,{newi,newj}});
                        }
                   
                }
            }
        }
        return -1;
    }
};