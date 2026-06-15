class Solution {
    int row[]={-1,0,1,0};
    int col[]={0,1,0,-1};
    boolean check(int i,int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    public int orangesRotting(int[][] grid) {
        int n=grid.length;
        int m=grid[0].length;
        int f=0;
        Queue<int[]>q=new LinkedList<>();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.offer(new int[]{i,j});
                }
                if(grid[i][j]==1)f++;
            }
        }
        if(f==0) return 0;
        int c=0;
        while(!q.isEmpty()){
            int size=q.size();
            c++;
            for(int s=0;s<size;s++){
                int[] pair=q.poll();
            for(int k=0;k<4;k++){
                int newi=pair[0]+row[k];
                int newj=pair[1]+col[k];
                if(check(newi,newj,n,m) && grid[newi][newj]==1){
                    q.offer(new int[]{newi,newj});
                    grid[newi][newj]=2;
                }
            }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return c-1;
    }
}