
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m,vector<int>(m,INT_MIN))
        );

        // Base case: Robot 1 at 0, Robot 2 at m-1
        dp[0][0][m-1] = grid[0][0] + grid[0][m-1];

        if(m==1)
            dp[0][0][0]=grid[0][0];

        for(int i=1;i<n;i++){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){

                    int cherries=grid[i][j1];

                    if(j1!=j2)
                        cherries+=grid[i][j2];

                    int mx=INT_MIN;

                    // Check all 9 previous positions
                    for(int d1=-1;d1<=1;d1++){
                        for(int d2=-1;d2<=1;d2++){

                            int p1=j1-d1;
                            int p2=j2-d2;

                            if(p1>=0 && p1<m && p2>=0 && p2<m){
                                if(dp[i-1][p1][p2]!=INT_MIN){
                                    mx=max(mx,dp[i-1][p1][p2]);
                                }
                            }
                        }
                    }

                    if(mx!=INT_MIN)
                        dp[i][j1][j2]=cherries+mx;
                }
            }
        }

        int ans=INT_MIN;

        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                ans=max(ans,dp[n-1][j1][j2]);
            }
        }

        return ans;
    }
};
