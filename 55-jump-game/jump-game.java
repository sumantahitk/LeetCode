class Solution {
    public boolean canJump(int[] nums) {
        if(nums.length >1 && nums[0]==0) return false;
        int mx=0;
        for(int i=0;i<nums.length;i++){
            if(mx<i) return false;
            int sum=nums[i]+i;
            mx=Math.max(mx,sum);
        } 
        return true;
    }
}