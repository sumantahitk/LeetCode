class Solution {
public:
    int row[4] = {-1, 0, +1, 0};
    int col[4] = {0, +1, 0, -1};
    bool verify(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size(),total=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    grid[i][j]='0';
                    q.push({i,j});
                    total++;
                    while(!q.empty()){
                        int a=q.front().first;
                        int b=q.front().second;
                        
                        q.pop();
                        for(int k=0;k<4;k++){
                        int ni=row[k]+a;
                        int nj=col[k]+b;
                        if(verify(ni,nj,n,m) && grid[ni][nj]=='1'){
                            q.push({ni,nj});
                            grid[ni][nj]='0';
                        }
                    }
                }
                    
                }
            }
        }
        return total;
    }
};