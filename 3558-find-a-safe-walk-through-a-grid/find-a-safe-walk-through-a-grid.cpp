class Solution {
public:

    int row[4] = {-1, 0, 1, 0};
    int col[4] = {0, 1, 0, -1};

    bool verify(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>> q;

        int startHealth = health - grid[0][0];

        if(startHealth <= 0)
            return false;

        q.push({{0,0}, startHealth});

        vector<vector<int>> best(n, vector<int>(m, -1));

        best[0][0] = startHealth;

        while(!q.empty()) {

            int u = q.front().first.first;
            int v = q.front().first.second;
            int rem = q.front().second;

            q.pop();

            if(u == n-1 && v == m-1)
                return true;

            for(int i=0; i<4; i++) {

                int newi = u + row[i];
                int newj = v + col[i];

                if(verify(newi, newj, n, m)) {

                    int newHealth = rem - grid[newi][newj];

                    if(newHealth > 0 &&
                       newHealth > best[newi][newj]) {

                        best[newi][newj] = newHealth;

                        q.push({{newi,newj}, newHealth});
                    }
                }
            }
        }

        return false;
    }
};