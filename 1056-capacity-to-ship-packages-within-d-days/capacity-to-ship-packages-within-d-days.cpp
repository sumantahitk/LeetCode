class Solution {
public:
int find(vector<int>&wt,int d){
    int sum=0,cnt=0;
    for(int i=0;i<wt.size();i++){
        if(sum+wt[i]<=d){
            sum+=wt[i];
        }else{
            sum=wt[i];
            cnt++;
        }
    }
    return cnt+1;

}
    int shipWithinDays(vector<int>& wt, int days) {
        int n=wt.size(),l=0,h=0,ans=0;
        for(int i=0;i<n;i++){
            h+=wt[i];
            l=max(l,wt[i]);
        }

        while(l<=h){
            int mid=(l+h)/2;
            int a=find(wt,mid);
            if(a<=days){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};