class Solution {
    public int[] twoSum(int[] nums, int tar) {
        Map<Integer,Integer>mp=new HashMap<>();

        for(int i=0;i<nums.length;i++){

            if(mp.containsKey(tar-nums[i])){
                return new int[]{i,mp.get(tar-nums[i])};
            }
            mp.put(nums[i],i);
        }

        return new int[]{};
    }
}