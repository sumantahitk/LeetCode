class Solution {
public:
    int row[4]={-1,0,+1,0};
    int col[4]={0,+1,0,-1};
    bool verify(int i,int j,int n,int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    void solve(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            if(grid[i][0]=='O'){
                q.push({i,0});
                grid[i][0]='A';
            }
            if(grid[i][m-1]=='O'){
                q.push({i,m-1});
                grid[i][m-1]='A';
            }
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]=='O'){
                q.push({0,j});
                grid[0][j]='A';
            }
            if(grid[n-1][j]=='O'){
                q.push({n-1,j});
                grid[n-1][j]='A';
            }
        }
        
        while(!q.empty()){
           
                int u=q.front().first;
                int v=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int newi=u+row[k];
                    int newj=v+col[k];
                    if(verify(newi,newj,n,m) && grid[newi][newj]=='O'){
                        q.push({newi,newj});
                        grid[newi][newj]='A';
                    }
                
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='O') grid[i][j]='X';
                else if(grid[i][j]=='A') grid[i][j]='O';
            }
        }
    }
};