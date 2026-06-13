class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer>st=new HashSet<>();
        int n=nums.length,ans=0;
        for(int i=0;i<n;i++){
            st.add(nums[i]);
        }

        for(int e:st){
            if(!st.contains(e-1)){
                int start=e;
                int cnt=1;
                while(st.contains(start+1)){
                    start++;
                    cnt++;
                }
                ans=Math.max(ans,cnt);
            }
        }
        return ans;
    }
}