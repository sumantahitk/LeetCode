class Solution {
public:
    int row[8]={-1,-1,0,1,1,1,0,-1};
    int col[8]={0,1,1,1,0,-1,-1,-1};
    bool verify(int i,int j,int n,int m){
        return i<n && i>=0 && j<m && j>=0;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1||grid[n-1][m-1]==1) return -1;

        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
     
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[0][0]=1;
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int total=q.front().second;
            q.pop();
            
            if(i==n-1 && j==m-1) return total;
            for(int k=0;k<8;k++){
                int newi=row[k]+i;
                int newj=col[k]+j;
                if(verify(newi,newj,n,m) && !vis[newi][newj] && grid[newi][newj]==0){
                    vis[newi][newj]=1;
                    q.push({{newi,newj},total+1});
                }
            }
        }
        return -1;
    }
};