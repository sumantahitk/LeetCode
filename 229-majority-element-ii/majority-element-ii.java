class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int e1=-1,e2=-1,c1=0,c2=0;
        int n=nums.length;
        int i=0;
        while(i<n){
            if(c1==0 && e2!=nums[i]){
                c1++;
                e1=nums[i];
            }
            else if(c2==0 && e1!=nums[i]){
                c2++;
                e2=nums[i];
            }
            else if(e1==nums[i]) c1++;
            else if(e2==nums[i]) c2++;
            else{
                c1--;
                c2--;
            }
            i++;
        }
        int cnt1=0,cnt2=0;
        i=0;
        for(i=0;i<n;i++){
            if(nums[i]==e1) cnt1++;
            if(nums[i]==e2) cnt2++;
        }
        ArrayList<Integer>list=new ArrayList<>();
        if(cnt1>n/3) list.add(e1);
        if(cnt2>n/3 && e1!=e2) list.add(e2);
        return list;
    }
}