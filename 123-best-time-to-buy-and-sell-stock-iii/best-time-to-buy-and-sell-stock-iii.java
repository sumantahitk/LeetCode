import java.util.Arrays;

class Solution {

    int solve(int[] prices, int buy,
              int i, int[][][] dp,
              int k) {

        if(i == prices.length || k == 0)
            return 0;

        if(dp[i][buy][k] != -1)
            return dp[i][buy][k];

        int ans;

        if(buy == 1) {

            ans = Math.max(
                    -prices[i] + solve(prices, 0, i + 1, dp, k),
                    solve(prices, 1, i + 1, dp, k)
                  );

        } else {

            ans = Math.max(
                    prices[i] + solve(prices, 1, i + 1, dp, k - 1),
                    solve(prices, 0, i + 1, dp, k)
                  );
        }

        return dp[i][buy][k] = ans;
    }

    public int maxProfit(int[] prices) {

        int n = prices.length;
        int k = 2;

        int[][][] dp = new int[n][2][k + 1];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 2; j++) {
                Arrays.fill(dp[i][j], -1);
            }
        }

        return solve(prices, 1, 0, dp, k);
    }
}