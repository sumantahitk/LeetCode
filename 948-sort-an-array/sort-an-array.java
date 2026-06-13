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
    void heapify(int i,int[] arr,int n){
        
        while(true){
            int largest=i;
            int left=2*i+1,right=2*i+2;
            if(left<n && arr[left]>arr[largest])
                largest=left;
            if(right<n && arr[right]>arr[largest])
                largest=right;
            
            if(i==largest) break;

            int temp=arr[largest];
            arr[largest]=arr[i];
            arr[i]=temp;
            i=largest;
        }
    }
    void heapsort(int [] arr,int n){
        // Build Max Heap
        for(int i=n/2-1;i>=0;i--){
            heapify(i,arr,n);
        }

        for(int i=n-1;i>=0;i--){
            int temp=arr[i];
            arr[i]=arr[0];
            arr[0]=temp;
            heapify(0,arr,i);
        }
    }
    public int[] heap(int[] arr) {
        int n=arr.length;
       heapsort(arr,n);
        return arr;
    }
    void margearr(int l,int m,int h,int[] arr){
        int a[]=new int[m-l+1];
        int b[]=new int[h-m];
        int ans[]=new int[h-l+1];
        int i=l,j=m+1;
        int p=0,k=0;
        while(i<=m && j<=h){
            if(arr[i]<arr[j]){
                ans[p++]=arr[i++];
            }else{
                ans[p++]=arr[j++];
            }
        }
        while(i<=m){
             ans[p++]=arr[i++];
        }
        while(j<=h){
            ans[p++]=arr[j++];
        }
        int e=0;
        for(int c=0;c<ans.length;c++){
            arr[c+l]=ans[c];
        }
    }
    void margesort(int l,int h,int[]arr){
        if(l>=h) return;

        int mid=(l+h)/2;
        margesort(l,mid,arr);
        margesort(mid+1,h,arr);
        margearr(l,mid,h,arr);
    }
    public int[] marge(int[] arr) {
        int n=arr.length;
       margesort(0,n-1,arr);
        return arr;
    }
    public int[] sortArray(int[] arr) {
    // return bubble(arr);
        // return selection(arr);
        // return insertion(arr);
        // return quick(arr);
        // return marge(arr);
        return heap(arr);
    }
}