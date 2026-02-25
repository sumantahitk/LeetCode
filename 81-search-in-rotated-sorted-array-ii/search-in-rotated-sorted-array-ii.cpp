class Solution {
public:
    bool search(vector<int>& arr, int tar) {
          int l=0,h=arr.size()-1;
        
        while(l<=h){
            int mid=(l+h)/2;
            if(arr[mid]==tar) return 1;
            if(arr[l]==arr[mid] && arr[mid]==arr[h]) {
                l++;
                h--;
            }
           else if(arr[l]<= arr[mid]){
                if(arr[l]<=tar && tar<=arr[mid]){
                    h=mid-1;
                }else{
                    l=mid+1;
                }
            }else{
                if(arr[mid]<=tar && tar<=arr[h]){
                    l=mid+1;
                }else{
                    h=mid-1;
                }
            }
        }
        return 0;
    }
};