class Solution {
    public List<List<Integer>> generate(int n) {
        List<List<Integer>> ans=new ArrayList<>();
        for(int i=0;i<n;i++){
            List<Integer>list=new ArrayList<>();
            for(int j=0;j<=i;j++){
                list.add(1);
            }

            for(int j=1;j<i;j++){
                list.set(j,ans.get(i-1).get(j)+ans.get(i-1).get(j-1));
            }
            ans.add(list);
        }
        return ans;
    }
}