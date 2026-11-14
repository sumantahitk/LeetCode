
import java.util.Arrays;

class Solution {
    long find(int state, int n, int m, int k, int[] p, long[][][] dp) {
        if (n >= m) {
            return state == 0 ? 0 : Long.MIN_VALUE / 2;
        }

        if (k == 0) {
            return state == 0 ? 0 : Long.MIN_VALUE / 2;
        }

        if (dp[n][state][k] != -1)
            return dp[n][state][k];

        long ans;

        if (state == 0) {
            // Start normal transaction OR short transaction OR skip
            ans = Math.max(
                -p[n] + find(1, n + 1, m, k, p, dp),
                Math.max(
                    p[n] + find(2, n + 1, m, k, p, dp),
                    find(0, n + 1, m, k, p, dp)
                )
            );
        } else if (state == 1) {
            // Sell OR continue holding
            ans = Math.max(
                p[n] + find(0, n + 1, m, k - 1, p, dp),
                find(1, n + 1, m, k, p, dp)
            );
        } else {
            // Buy back short OR continue short
            ans = Math.max(
                -p[n] + find(0, n + 1, m, k - 1, p, dp),
                find(2, n + 1, m, k, p, dp)
            );
        }

        return dp[n][state][k] = ans;
    }

    public long maximumProfit(int[] p, int k) {
        int n = p.length;
        long[][][] dp = new long[n][3][k + 1];

        for (long[][] a : dp)
            for (long[] b : a)
                Arrays.fill(b, -1);

        return find(0, 0, n, k, p, dp);
    }
}
