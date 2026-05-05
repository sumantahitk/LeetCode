class Solution {
public:
    int find(int u, vector<int>& par){
        if(u == par[u]) return u;
        return par[u] = find(par[u], par);
    }

    void unionBySize(int u, int v, vector<int>& par, vector<int>& size){
        int pu = find(u, par);
        int pv = find(v, par);

        if(pu == pv) return;

        if(size[pu] > size[pv]){
            par[pv] = pu;
            size[pu] += size[pv];
        } else {
            par[pu] = pv;
            size[pv] += size[pu];
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int N = n * n;

        vector<int> par(N), size(N, 1);

        for(int i = 0; i < N; i++) par[i] = i;

        int row[4] = {-1,0,0,1};
        int col[4] = {0,-1,1,0};

        // Step 1: connect all 1s
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    for(int k = 0; k < 4; k++){
                        int ni = i + row[k];
                        int nj = j + col[k];

                        if(ni>=0 && nj>=0 && ni<n && nj<n && grid[ni][nj]==1){
                            int node = i*n + j;
                            int nei  = ni*n + nj;
                            unionBySize(node, nei, par, size);
                        }
                    }
                }
            }
        }

        int ans = 0;

        // Step 2: try converting each 0
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){

                    set<int> st;

                    for(int k = 0; k < 4; k++){
                        int ni = i + row[k];
                        int nj = j + col[k];

                        if(ni>=0 && nj>=0 && ni<n && nj<n && grid[ni][nj]==1){
                            int parent = find(ni*n + nj, par);
                            st.insert(parent);
                        }
                    }

                    int total = 1;

                    for(auto it : st){
                        total += size[it];
                    }

                    ans = max(ans, total);
                }
            }
        }

        // Step 3: edge case (all 1s)
        for(int i = 0; i < N; i++){
            ans = max(ans, size[find(i, par)]);
        }

        return ans;
    }
};