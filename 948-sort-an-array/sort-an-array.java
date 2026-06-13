class Solution {
     public int[] bubble(int[] arr) {
        int n=arr.length;
        for(int i=0;i<n-1;i++){
            int flag=0;
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                    flag=1;
                }
            }
            if(flag==0) break;
        }
        return arr;
    }
     public int[] selection(int[] arr) {
        int n=arr.length;
       for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        if(min!=i){
            int temp=arr[min];
                arr[min]=arr[i];
                arr[i]=temp;
        }
       }
        return arr;
    }
    public int[] insertion(int[] arr) {
        int n=arr.length;
        for(int i=1;i<n;i++){
            int j=i-1;
            int key=arr[i];
            while(j>=0 && key<arr[j]){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }
        return arr;
    }
    int partition(int l,int h,int[]arr){
    int randomIndex = l + (int)(Math.random() * (h - l + 1));
    int t = arr[l];
    arr[l] = arr[randomIndex];
    arr[randomIndex] = t;
    int pivot=arr[l];
        int i=l,j=h;
        while(i<j){
            while(i<h && arr[i]<=pivot){
                i++;
            }
            while(j>l && arr[j]>pivot){
                j--;
            } 
            if(i<j){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
         int temp=arr[l];
            arr[l]=arr[j];
            arr[j]=temp;
        return j;

    }
    void quicksort(int l,int h,int[] arr){
        if(l>=h){
            return;
        }
        int par=partition(l,h,arr);
        quicksort(l,par-1,arr);
        quicksort(par+1,h,arr);
    }
    public int[] quick(int[] arr) {
        int n=arr.length;
        quicksort(0,n-1,arr);
       
        return arr;
    }
    public int[] heap(int[] arr) {
        int n=arr.length;
       
        return arr;
    }
    public int[] marge(int[] arr) {
        int n=arr.length;
       
        return arr;
    }
    public int[] sortArray(int[] arr) {
    // return bubble(arr);
        // return selection(arr);
        // return insertion(arr);
        return quick(arr);
    }
}