
class Solution {
    int find(int n, int tar, int[][] dp, int[] coins) {
        if(tar == 0) return 1;
        if(n == 0) return 0;

        if(dp[n][tar] != -1)
            return dp[n][tar];

        if(tar >= coins[n-1]) {
            dp[n][tar] = find(n, tar-coins[n-1], dp, coins)
                        + find(n-1, tar, dp, coins);
        } else {
            dp[n][tar] = find(n-1, tar, dp, coins);
        }

        return dp[n][tar];
    }

    public int change(int amount, int[] coins) {
        int n = coins.length;

        int[][] dp = new int[n+1][amount+1];

        for(int[] row : dp)
            Arrays.fill(row, -1);

        return find(n, amount, dp, coins);
    }
}

