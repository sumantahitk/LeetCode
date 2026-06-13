class Solution {
    public int majorityElement(int[] nums) {
        int c=0,i=0,e=-1,n=nums.length;
        while(i<n){
            if(c==0){
                c=1;
                e=nums[i];
            }
           else if(e==nums[i])c++;
            else{
                c--;
            }
            i++;
        }
        
        return e;
    }
}