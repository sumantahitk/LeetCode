class Solution {
public:
int find(int i,vector<int>&v,vector<int>&nums){
    if(i==0) return nums[i];
    if(i<0) return 0;
    if(v[i]!=-1) return v[i];
    int take =find(i-2,v,nums)+nums[i];
    int nottake=find(i-1,v,nums);
    
     return v[i]=max(take,nottake);
}
    int rob(vector<int>& nums) {
        
        int i=nums.size()-1;
        vector<int>v(i+1,-1);
        return find(i,v,nums);
    }
};