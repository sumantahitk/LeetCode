class Solution {
public:
    int find(int n,int amt,vector<int>&c,vector<vector<int>>&arr,int &ans){
        
        // if(n==0) return 0;
        if(n==0) return INT_MAX -1;
        if(amt==0) return 0;
        if(arr[n][amt]!=-1) return arr[n][amt];
        if(amt>=c[n-1]){
            arr[n][amt]=min(find(n,amt-c[n-1],c,arr,ans)+1,find(n-1,amt,c,arr,ans));
        }
        else{
             arr[n][amt]=find(n-1,amt,c,arr,ans);
        }
        return arr[n][amt];
    }
    int coinChange(vector<int>& c, int amt) {
        int n=c.size();
        vector<vector<int>>arr(n+1,vector<int>(amt+1,-1));
        int ans=0;
        ans=find(n,amt,c,arr,ans);
        if(ans==INT_MAX-1) return -1;
        return ans;
    }
};