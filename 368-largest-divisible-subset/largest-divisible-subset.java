class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
         int n=nums.length,mx=Integer.MIN_VALUE, lastidx=-1;
               int[] dp=new int[n];
               int []hash=new int[n];
               Arrays.sort(nums);
               Arrays.fill(dp,1);
               for(int i=0;i<n;i++){
                   hash[i]=i;
                   for(int j=0;j<i;j++){
                       if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                           dp[i]=dp[j]+1;
                           hash[i]=j;
                       }
                   }
                   if(dp[i]>mx){
                       mx=dp[i];
                       lastidx=i;
                   }
               }
               ArrayList<Integer>arr=new ArrayList<>();
               arr.add(nums[lastidx]);
               while(hash[lastidx]!=lastidx){
                   lastidx=hash[lastidx];
                   arr.add(nums[lastidx]);
               }
               Collections.reverse(arr);
               return arr;
    }
}