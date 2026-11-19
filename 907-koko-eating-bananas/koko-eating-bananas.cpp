class Solution {
public:
    long long  find(int &ans,vector<int>&p,int h){
        long long cnt=0;
        for(int i=0;i<p.size();i++){
            cnt+=ceil((double)p[i]/ans);
        }
        return cnt;
    }
    int minEatingSpeed(vector<int>& p, int h) {
         int mx=0;
        for(int i=0;i<p.size();i++){
            if(p[i]>mx){
                mx=p[i];
            }
        }
        int i=1,j=mx,a=-1;
        while(i<=j){
            int mid=(i+j)/2;
            long long  ans=find(mid,p,h);
            if(ans<=h){
                a=mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return a;
    }
};