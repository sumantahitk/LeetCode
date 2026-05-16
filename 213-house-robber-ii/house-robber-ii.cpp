class Solution {
public:
int find(int i,vector<int>&v,vector<int>&nums){
      if(i<0) return 0;
    if(i==0) return nums[i];
  
    if(v[i]!=-1) return v[i];
    int take =find(i-2,v,nums) + nums[i];
    int nottake=find(i-1,v,nums);
    
     return v[i]=max(take,nottake);
}
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int>v1,v2;
        vector<int>v(nums.size(),-1);
        vector<int>s(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            if(i!=0)v1.push_back(nums[i]);
            if(i!=nums.size()-1) v2.push_back(nums[i]);
        }
        int i=v1.size()-1;
        return max(find(i,v,v1),find(i,s,v2));
    }
};