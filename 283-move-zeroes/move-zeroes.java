class Solution {
    public void moveZeroes(int[] arr) {
        int n=arr.length;
        int i=0;
        while(i<n){
            if(i+1<n && arr[i]==0){
                int j=i+1;
                while(j<n && arr[j]==0)j++;
                if(j==n)break;
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;  
            }
                i++;
            
        }
    }
}