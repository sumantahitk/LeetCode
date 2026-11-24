class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size(),ans=0;
        mp[0]=1;
        int total=0;
        for(int i=0;i<n;i++){
            ans+=nums[i];
            if(mp.find(ans-k)!=mp.end()){
                total+=mp[ans-k];
            }
            mp[ans]++;
        }
        return total;
    }
};