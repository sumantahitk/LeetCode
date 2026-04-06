class Solution {
    public int[] arrayRankTransform(int[] arr) {
        int[] nums=arr.clone();
        Arrays.sort(nums);
        int rank=1;
        Map<Integer,Integer> mp=new HashMap<>();
        for(int i=0;i<nums.length;i++){
            if(!mp.containsKey(nums[i]))
            mp.put(nums[i],rank++);
          
        }
        for(int i=0;i<arr.length;i++){
          
            arr[i]=mp.get(arr[i]);
        }
        return arr;
    }
}