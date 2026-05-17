class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums[0]==0 && nums.size()>1) return 0;
        int mx=0,sum=0;
        for(int i=0;i<nums.size();i++){
            if(mx<i) return 0;
            sum=nums[i]+i;
            mx=max(mx,sum);
        }
        return 1;
    }
};