class Solution {
    public long maximumProfit(int[] prices, int k) {
        int n = prices.length;
        if (n == 0 || k == 0) return 0;

        //DO Again!
        //DO Again!
        //DO Again!


        // dp[t][0] = idle (holding nothing) after t completed transactions
        // dp[t][1] = holding long position (working towards transaction t+1)
        // dp[t][2] = holding short position (working towards transaction t+1)
        long[][] dp = new long[k + 1][3];

        // Initialize state table with negative infinity for impossible states
        for (int t = 0; t <= k; t++) {
            dp[t][0] = (t == 0) ? 0 : Long.MIN_VALUE / 2;
            dp[t][1] = Long.MIN_VALUE / 2;
            dp[t][2] = Long.MIN_VALUE / 2;
        }

        for (int price : prices) {
            long[][] nextDp = new long[k + 1][3];
            for (int t = 0; t <= k; t++) {
                nextDp[t][0] = dp[t][0];
                nextDp[t][1] = dp[t][1];
                nextDp[t][2] = dp[t][2];
            }

            for (int t = 0; t <= k; t++) {
                // 1. Close a Long position -> completes transaction t (from t-1)
                if (t > 0 && dp[t - 1][1] != Long.MIN_VALUE / 2) {
                    nextDp[t][0] = Math.max(nextDp[t][0], dp[t - 1][1] + price);
                }

                // 2. Close a Short position -> completes transaction t (from t-1)
                if (t > 0 && dp[t - 1][2] != Long.MIN_VALUE / 2) {
                    nextDp[t][0] = Math.max(nextDp[t][0], dp[t - 1][2] - price);
                }

                // 3. Open a Long position (start transaction t+1)
                if (t < k && dp[t][0] != Long.MIN_VALUE / 2) {
                    nextDp[t][1] = Math.max(nextDp[t][1], dp[t][0] - price);
                }

                // 4. Open a Short position (start transaction t+1)
                if (t < k && dp[t][0] != Long.MIN_VALUE / 2) {
                    nextDp[t][2] = Math.max(nextDp[t][2], dp[t][0] + price);
                }
            }

            dp = nextDp; // Move to next day
        }

        long maxProfit = 0;
        for (int t = 0; t <= k; t++) {
            maxProfit = Math.max(maxProfit, dp[t][0]);
        }

        return maxProfit;
    }
}