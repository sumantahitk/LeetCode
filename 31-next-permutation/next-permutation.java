class Solution {
     public void rev(int[] arr,int l,int h){
        while(l<h){
            int temp=arr[l];
            arr[l]=arr[h];
            arr[h]=temp;
            l++;
            h--;
        }
    } 
    public void nextPermutation(int[] nums) {
        int n=nums.length,id=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                id=i;
                break;
            }
        }
        if(id==-1){
            rev(nums,0,n-1);
            return;
        }
        for(int i=n-1;i>=0;i--){
            if(nums[id]<nums[i]){
                int temp=nums[id];
                nums[id]=nums[i];
                nums[i]=temp;
                break;
            }
        }
        rev(nums,id+1,n-1);
    }
}