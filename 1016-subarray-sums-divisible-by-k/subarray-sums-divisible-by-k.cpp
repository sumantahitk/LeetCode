class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int rem=0;
        map<int,int>mp;
        mp[0]=1;
        int presum=0,total=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            presum+=nums[i];
            rem=(presum%k);
            if(rem<0) rem+=k;
            if(mp.count(rem)){
                total+=mp[rem];

            }
            mp[rem]++;
        }
        return total;
    }
};