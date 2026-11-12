class Solution {
    public int minSubArrayLen(int tar, int[] nums) {
       int sum=0,cnt=0,mn=Integer.MAX_VALUE,l=0,h=0,n=nums.length;
       while(h<n){
            sum+=nums[h];
            while(l<=h && sum>=tar){
                cnt+=n-1-h;
                mn=Math.min(mn,h-l+1);
                sum-=nums[l];
                l++;
            }
            h++;
       }
       if(mn==Integer.MAX_VALUE) return 0;
       
       return mn;
    }
}