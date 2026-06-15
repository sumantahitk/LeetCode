class Solution {
    void dfs(int i,int[]vis,ArrayList<ArrayList<Integer>>adj){
        vis[i]=1;
        for(int j=0;j<adj.get(i).size();j++){
            if(vis[adj.get(i).get(j)]==0){
                dfs(adj.get(i).get(j),vis,adj);
            }
        }
    }
    public int findCircleNum(int[][] con) {
        int n=con.length;
        ArrayList<ArrayList<Integer>>adj=new ArrayList<>();
        for(int i=0;i<n;i++){
            adj.add(new ArrayList<>());
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(con[i][j]==1){
                    adj.get(i).add(j);
                }
            }
        }
        int size=adj.size(),c=0;
        int vis[]=new int[size];
        for(int i=0;i<adj.size();i++){
            if(vis[i]==0){
                c++;
                dfs(i,vis,adj);
            }
        }
        return c;
    }
}