class Solution {
    public void sortColors(int[] nums) {
        int n=nums.length;
        int a=0,b=0,c=n-1;
        while(a<n){
            if(a<c && nums[a]==2){
                int temp=nums[a];
                nums[a]=nums[c];
                nums[c]=temp;
                c--;
                continue;
            }
            else if(nums[a]==0){
                 int temp=nums[a];
                nums[a]=nums[b];
                nums[b]=temp;
                a++;
                b++;
            }else{
                a++;
            }
        }
    }
}