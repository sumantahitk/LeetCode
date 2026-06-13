class Solution {
    public int removeDuplicates(int[] nums) {
        int n=nums.length;
        int i=1,j=0;
        while(i<n){
            if(nums[i]!=nums[j]){
                nums[j+1]=nums[i];
                j++;
            }
            i++;
        }
        return j+1;
    }
}