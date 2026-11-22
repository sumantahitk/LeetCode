class Solution {
    int find(int[] nums,int mid){
        int sum=0,c=1;
        for(int i=0;i<nums.length;i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }else{
                c++;
                sum=nums[i];
            }
        }
        return c;
    }
    public int splitArray(int[] nums, int k) {
        
        int l=0,h=0,mx=0,ans=0,n=nums.length;
        for(int i=0;i<n;i++){
            l=Math.max(l,nums[i]);
            h+=nums[i];

        }
        while(l<=h){
            int mid=(l+h)/2;
            int a=find(nums,mid);
            if(a<=k){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
}