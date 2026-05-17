class Solution {
public:
    bool find(int i,int n,vector<int>&arr,int s,vector<bool>&visited){
        if(i<0 || i>=n) return 0;
        if(arr[i]==0) return 1;
        if(visited[i]!=0) return 0;

        visited[i]=1;
        bool left=find(i-arr[i],n,arr,s,visited);
        bool right=find(i+arr[i],n,arr,s,visited);
        return left||right;

    }
    bool canReach(vector<int>& arr, int s) {
        int i=s;
        int n=arr.size();
        vector<bool>visited(n,0);
        return find(i,arr.size(),arr,s,visited);
    }
};