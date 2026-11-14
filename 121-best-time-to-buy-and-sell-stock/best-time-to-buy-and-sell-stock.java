class Solution {
    public int maxProfit(int[] p) {
        int ans=p[0],mx=0;
        for(int i=1;i<p.length;i++){
            int pr=p[i]-ans;
            mx=Math.max(mx,pr);
            ans=Math.min(ans,p[i]);
        }
        return mx;
    }
}