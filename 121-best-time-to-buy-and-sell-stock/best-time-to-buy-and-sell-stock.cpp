class Solution {
public:
    int maxProfit(vector<int>& p) {
        int mx=0,a=p[0];
        for(int i=1;i<p.size();i++){
            int profit=p[i]-a;
            mx=max(mx,profit);
            a=min(p[i],a);
        }
        return mx;
    }
};