class Solution {
public:
 int row[4] = {-1, 0, +1, 0};
    int col[4] = {0, +1, 0, -1};
    bool verify(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int c=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    
                    grid[i][j]='2';
                    q.push({i,j});
                    c++;
                    while(!q.empty()){
                        int u=q.front().first;
                        int v=q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++){
                        int newi=u+row[k];
                        int newj=v+col[k];
                        if(verify(newi,newj,n,m) && grid[newi][newj]=='1'){
                            q.push({newi,newj});
                            grid[newi][newj]='2';
                        }
                    }
                    }
                }
            }
        }
        return c;
    }
};