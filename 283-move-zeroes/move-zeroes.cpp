class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int c1=0,c2=0,c3=nums.size()-1;
        while(c1<c3){
            if(nums[c1]==0){
                while(c1<c3 && nums[c1]==0){
                    c1++;;
                }
                swap(nums[c1],nums[c2]);
                c2++;
            }else
            {
            c1++;
            c2++;
            }}
    }
};