class Solution {
public:
    long long find(vector<int>&p,int day,int k){
        long long cnt=0,ans=0;
        for(int i=0;i<p.size();i++){
            if(p[i]<=day){
                cnt++;
            }else{
                ans=ans+cnt/k;
                cnt=0;
            }
        }
        ans+=(cnt/k);
        return ans;
    }
    int minDays(vector<int>& b, int m, int k) {
        
        int l=1,n=b.size(),h=0,ans=0;
        if(m>(n/k)) return -1;
        for(int i=0;i<n;i++){
            h=max(h,b[i]);
        }

        while(l<=h){
            int mid=(l+h)/2;
            long long a=find(b,mid,k);
            if(a>=m){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};