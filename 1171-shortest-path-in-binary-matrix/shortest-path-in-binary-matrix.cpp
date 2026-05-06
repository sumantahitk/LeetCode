class Solution {
public:
    int row[8]={-1,-1,0,1,1,1,0,-1};
    int col[8]={0,1,1,1,0,-1,-1,-1};
    bool verify(int i,int j,int n,int m){
        return i<n && i>=0 && j<m && j>=0;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;

        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        q.push({{0,0},1});
        grid[0][0]=1;
        // int cnt=0
        while(!q.empty()){
            int u=q.front().first.first;
            int v=q.front().first.second;
            int cnt=q.front().second;
            q.pop();
            if(u==n-1 && v==n-1){
                return cnt;
            }
            for(int k=0;k<8;k++){
                int newi=u+row[k];
                int newj=v+col[k];
                if(verify(newi,newj,n,n) && grid[newi][newj]==0){
                    grid[newi][newj]=1;
                    q.push({{newi,newj},cnt+1});
                }
            }
        }
        return -1;
    }
};