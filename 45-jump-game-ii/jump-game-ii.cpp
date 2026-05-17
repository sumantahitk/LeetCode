class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int a=0,b=0,cnt=0;
        for(int i=0;i<n-1;i++){
            a=max(a,nums[i]+i);
            if(b==i){
                b=a;
                cnt++;
            }
        }
        return cnt;
    }
};