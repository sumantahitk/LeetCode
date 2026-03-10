class Solution {
    public boolean find(int[][]mat,int a,int b){
        for(int i=0;i<mat[0].length;i++){
            if(i!=b && mat[a][i]==1){
                //  System.out.println(mat[a][i]+" "+a+" "+i);
                 return true;
                 }
        }
        for(int i=0;i<mat.length;i++){
            if(a!=i && mat[i][b]==1){
                //  System.out.println(mat[i][b]+" "+i+" "+b);
                 return true;
                 }
        }
        return false;
    }
    public int numSpecial(int[][] mat) {
        int c=0;
        for(int i=0;i<mat.length;i++){
            for(int j=0;j<mat[i].length;j++){
                if(mat[i][j]==1){
                    // System.out.println(mat[i][j]+" "+i+" "+j);
                    if(find(mat,i,j)==false)c++;
                }
            }
        }
        return c;
    }
}