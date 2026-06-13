class Solution {
    public int maxProfit(int[] p) {
        int ans=0,cost=p[0];
        for(int i=0;i<p.length;i++){
            int profit=p[i]-cost;
            ans=Math.max(profit,ans);
            cost=Math.min(cost,p[i]);
        }
        return ans;
    }
}