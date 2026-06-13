class Solution {
    public List<Integer> spiralOrder(int[][] mat) {
        List<Integer>list=new ArrayList<>();
        int n=mat.length,m=mat[0].length;
        int sr=0,er=n-1,sc=0,ec=m-1;
        while(sr<=er && sc<=ec){
            for(int i=sc;i<=ec;i++){
                
               
               
                list.add(mat[sr][i]);


            }
            for(int i=sr+1;i<=er;i++){
                 
                list.add(mat[i][ec]);

            }
            for(int i=ec-1;i>=sc;i--){
                 if(sr==er) break ;
                list.add(mat[er][i]);
            }
            for(int i=er-1;i>sr;i--){
                if(sc==ec) break;
                list.add(mat[i][sc]);
            }
            sr++;
            er--;
            sc++;
            ec--;
        }
        return list;
    }
}