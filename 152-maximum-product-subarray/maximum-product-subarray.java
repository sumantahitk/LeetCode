class Solution {
    public int maxProduct(int[] nums) {
        int pr=1,su=1,n=nums.length;
        int prefix[]=new int[n];
        int suff[]=new int[n];
        prefix[0]=nums[0];
        for(int i=1;i<nums.length;i++){
            if(prefix[i-1]==0) prefix[i]=1*nums[i];
            else
            prefix[i]=prefix[i-1]*nums[i];
        }
        suff[n-1]=nums[n-1];
        for(int j=n-2;j>=0;j--){
            if(suff[j+1]==0) suff[j]=1*nums[j];
            else
            suff[j]=suff[j+1]*nums[j];
        }
        int mx=Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            mx=Math.max(mx,Math.max(prefix[i],suff[i]));
        }
        return mx;
    }
}