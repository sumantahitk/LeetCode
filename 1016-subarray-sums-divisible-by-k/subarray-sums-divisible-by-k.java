class Solution {
    public int subarraysDivByK(int[] nums, int k) {
         int n=nums.length,total=0;
        Map<Integer,Integer>mp=new HashMap<>();
        mp.put(0,1);
        int sum=0;
        for(int i=0;i<n;i++){
           sum+=nums[i];
          int rem=sum%k;
           if(rem<0){
            rem+=k;
           }
           if(mp.containsKey(rem)){
                total+=mp.get(rem);
           }
           mp.put(rem,mp.getOrDefault(rem,0)+1);
        }
        return total;
    }
}