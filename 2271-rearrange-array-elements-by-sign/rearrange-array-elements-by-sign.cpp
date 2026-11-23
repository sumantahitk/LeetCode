class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int e=0,o=1,i=0;
        vector<int>ans(n);
        while(i<n){
            if(nums[i]>0){
                ans[e]=nums[i];
                e+=2;
            }else{
                ans[o]=nums[i];
                o+=2;
            }
            i++;
        }
        return ans;
    }
};