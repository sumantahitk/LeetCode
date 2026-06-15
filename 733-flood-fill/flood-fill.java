class Solution {
    int row[]={-1,0,1,0};
    int col[]={0,1,0,-1};
    boolean check(int i,int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    public int[][] floodFill(int[][] grid, int sr, int sc, int co) {
        int a=grid[sr][sc];
        int n=grid.length;
        int m=grid[0].length;
        grid[sr][sc]=co;
        if(co==a) return grid;
        Queue<int[]>q=new LinkedList<>();
        q.offer(new int[]{sr,sc});
        while(!q.isEmpty()){
            int[] pair=q.poll();
            for(int k=0;k<4;k++){
                int newi=pair[0]+row[k];
                int newj=pair[1]+col[k];
                if(check(newi,newj,n,m) && grid[newi][newj]==a){
                    grid[newi][newj]=co;
                    q.offer(new int[]{newi,newj});
                }
            }
        }
        return grid;
    }
}