class Solution {
    public int findPeakElement(int[] arr) {
        int l=0,h=arr.length-1;
        if(l==h) return 0;
        if(arr[0]>arr[1]) return 0;
        if(arr[h]>arr[h-1]) return h;
        l++;
        h--;
        while(l<=h){
            int mid=(l+h)/2;
            if(mid-1>=0 && mid+1<arr.length && arr[mid-1]<=arr[mid] && arr[mid]>=arr[mid+1]) return mid;
            if(arr[l]==arr[mid] && arr[h]==arr[mid]){
                l++;
                h--;
            }
            else if(mid-1>=0 && arr[mid-1]<=arr[mid]){
                l=mid+1;
            }
            else if(mid+1<arr.length && arr[mid]>=arr[mid+1]){
                h=mid-1;
            }
            else{
               l=mid+1;
            }
        }
        return -1;
    }
}