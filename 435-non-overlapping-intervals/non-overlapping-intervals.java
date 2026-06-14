class Solution {
    public int eraseOverlapIntervals(int[][] in) {
        Arrays.sort(in,(a,b)->a[1]-b[1]);

        int n=in.length;
        int last=in[0][1];
        int c=0;
        for(int i=1;i<n;i++){

            if(in[i][0]<last){
                c++;
                
            }else{
                last=in[i][1];
            }
        }
        return c;
    }
}