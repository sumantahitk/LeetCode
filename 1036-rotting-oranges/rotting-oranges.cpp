class Solution {
public:
    int row[4]={-1,0,1,0};
    int col[4]={0,1,0,-1};
    bool isvalid(int i,int j,int n,int m){
        return i<n && i>=0 && j<m && j>=0;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int r=0,f=0;
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    r++;
                }
                if(grid[i][j]==1) f++;
            }
        }
        if(r==0 && f>0) return -1;
        if(r==0) return 0;
        int n=grid.size(),time=0;
        int m=grid[0].size();
        while(!q.empty()){
            int size=q.size();
            time++;
            for(int i=0;i<size;i++){
                int u=q.front().first;
                int v=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int newu=u+row[k];
                    int newv=v+col[k];
                    if(isvalid(newu,newv,n,m) && grid[newu][newv]==1){
                        grid[newu][newv]=2;
                        q.push({newu,newv});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                   
                    return -1;
                }
            }
        }
        return time-1;    
    }
};