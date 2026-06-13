class Solution {
    void reverse(int []arr,int l,int h){
        while(l<h){
            int temp=arr[l];
            arr[l]=arr[h];
            arr[h]=temp;
            l++;
            h--;
        }
    }
    public void rotate(int[] nums, int k) {
       int l=0,h=nums.length-1;
       int n=nums.length;
       k=k%n; 
       reverse(nums,l,h);
       reverse(nums,l,k-1);
       reverse(nums,k,h);
      
    }
}