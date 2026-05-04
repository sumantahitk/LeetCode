class Solution {
public:
    int row[4]={-1,0,+1,0};
    int col[4]={0,+1,0,-1};
    bool verify(int i,int j,int n,int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        queue<pair<int,int>>q;
        int n=grid.size(),m=grid[0].size();
        
        q.push({sr,sc});
        int key=grid[sr][sc];
        if (key == color) return grid;
          grid[sr][sc] = color;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int u=q.front().first;
                int v=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int newi=u+row[k];
                    int newj=v+col[k];
                    if(verify(newi,newj,n,m) && grid[newi][newj]==key){
                        q.push({newi,newj});
                        grid[newi][newj]=color;
                    }
                }
            }
        }
        return grid;
    }
};