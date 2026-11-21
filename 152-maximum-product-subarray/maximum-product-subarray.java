class Solution {
    public int maxProduct(int[] nums) {

        int n = nums.length;
        int mx = Integer.MIN_VALUE;
        int []pre=new int[n];
        int []suf=new int[n];
        pre[0]=nums[0];
        suf[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            if(pre[i-1]==0) pre[i]=1*nums[i];
            else pre[i]=pre[i-1]*nums[i];
        }
        for(int i=n-2;i>=0;i--){
            if(suf[i+1]==0) suf[i]=1*nums[i];
            else suf[i]=suf[i+1]*nums[i];
        }

        for(int i=0;i<n;i++){
            mx=Math.max(mx,Math.max(pre[i],suf[i]));
        }
      
        return mx;
    }
}