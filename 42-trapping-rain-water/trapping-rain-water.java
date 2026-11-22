class Solution {
    public int trap(int[] h) {
        int n=h.length,ans=0;
        int []pre=new int[n];
        int []suf=new int[n];
        pre[0]=h[0];
        suf[n-1]=h[n-1];
        for(int i=1;i<n;i++){
            pre[i]=Math.max(pre[i-1],h[i]);
        }
        for(int j=n-2;j>=0;j--){
            suf[j]=Math.max(suf[j+1],h[j]);
        }

        for(int i=0;i<n;i++){
            ans+=Math.min(pre[i],suf[i])-h[i];
        }
        return ans;

       
    }
}