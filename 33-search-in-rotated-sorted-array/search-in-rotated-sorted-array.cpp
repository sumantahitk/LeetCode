class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int l=0,h=nums.size()-1;
        
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==tar) return mid;
            if(nums[l]<=nums[mid]){
                if(nums[l]<=tar && tar<=nums[mid]){
                    h=mid-1;
                }else{
                    l=mid+1;
                }
            }
            else{
                if(nums[mid]<=tar && tar<=nums[h]){
                    l=mid+1;
                }else{
                    h=mid-1;
                }
            }
        }
        return -1;
    }
};