class Solution {
public:

    int row[4] = {-1, 0, 1, 0};
    int col[4] = {0, 1, 0, -1};

    bool verify(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    int shortestPath(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        // {{row,col},{steps,remaining_k}}
        queue<pair<pair<int,int>, pair<int,int>>> q;

        q.push({{0,0},{0,k}});

        vector<vector<vector<int>>> vis(
            n,
            vector<vector<int>>(m, vector<int>(k+1, 0))
        );

        vis[0][0][k] = 1;

        while(!q.empty()) {

            int u = q.front().first.first;
            int v = q.front().first.second;

            int step = q.front().second.first;
            int rem  = q.front().second.second;

            q.pop();

            if(u == n-1 && v == m-1)
                return step;

            for(int i=0; i<4; i++) {

                int newi = row[i] + u;
                int newj = col[i] + v;

                if(verify(newi, newj, n, m)) {

                    // Empty cell
                    if(grid[newi][newj] == 0 &&
                       !vis[newi][newj][rem]) {

                        vis[newi][newj][rem] = 1;

                        q.push({{newi,newj},{step+1,rem}});
                    }

                    // Obstacle cell
                    else if(grid[newi][newj] == 1 &&
                            rem > 0 &&
                            !vis[newi][newj][rem-1]) {

                        vis[newi][newj][rem-1] = 1;

                        q.push({{newi,newj},{step+1,rem-1}});
                    }
                }
            }
        }

        return -1;
    }
};