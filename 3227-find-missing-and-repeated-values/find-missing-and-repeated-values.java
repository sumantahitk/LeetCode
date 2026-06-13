class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int l=grid.length;
        int m=grid[0].length;
        long sum=0,sumsq=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                sum+=grid[i][j];
                sumsq+=(grid[i][j]*grid[i][j]);
            }
        }
          // Expected sum
          long n=m*m;
        long orisum = n * (n + 1) / 2;

        // Expected square sum
        long orisumsq =
                n * (n + 1) * (2 * n + 1) / 6;
        long diff=(orisum-sum);
        long diffsq=(orisumsq-sumsq);
        int added=(int)(diffsq/diff);
        int dub=(int)(added+diff)/2;
        int miss=added-dub;

        return new int[]{miss,dub};
    }
}