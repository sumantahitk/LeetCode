class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Set<List<Integer>>ans=new HashSet<>();
        for(int i=0;i<nums.length;i++){
            Set<Integer>seen=new HashSet<>();
            for(int j=i+1;j<nums.length;j++){
                int req=-(nums[i]+nums[j]);
                if(seen.contains(req)){
                    List<Integer>tri=new ArrayList<>();
                    tri.add(req);
                    tri.add(nums[i]);
                    tri.add(nums[j]);
                    Collections.sort(tri);
                    ans.add(tri);
                }
                seen.add(nums[j]);
            }
        }
        return new ArrayList<>(ans);
    }
}