class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& in) {
        
        int n=in.size();
        sort(in.begin(),in.end(),comp);
        int last=in[0][1],c=0;
        for(int i=1;i<n;i++){
            if(last<=in[i][0]){
                last=in[i][1];
            }else c++;
        }
        return c;
    }
};