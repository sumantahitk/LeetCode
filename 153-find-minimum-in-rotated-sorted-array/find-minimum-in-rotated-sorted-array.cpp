class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int l=0,ans=INT_MAX,h=nums.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[l]<=nums[mid]){
                ans=min(ans,nums[l]);
                l=mid+1;
            }else{
                h=mid;
            }

        }
        return ans;
    }
};