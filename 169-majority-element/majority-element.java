class Solution {
    public int majorityElement(int[] nums) {
        int e1=-1,c=0,i=0,n=nums.length;
        while(i<n){
            if(c==0){
                e1=nums[i];
                c++;
            }
            else if(e1==nums[i]){
                c++;
            }else{
                c--;
            }
            i++;
        }

        return e1;
    }
}