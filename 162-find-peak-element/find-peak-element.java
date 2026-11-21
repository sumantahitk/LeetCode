class Solution {
    public int findPeakElement(int[] nums) {
        int l=0,h=nums.length-1;
       if(l==h) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[h]>nums[h-1]) return h;
        l++;
        h--;
        int n=nums.length;
        while(l<=h){
            int mid=(l+h)/2;
            if(mid-1>=0 && mid+1<n && nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]) return mid;
            if(mid-1>=0 && nums[mid-1]<nums[mid]){
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return -1;
    }
}