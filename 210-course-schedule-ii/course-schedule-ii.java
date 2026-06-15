class Solution {
    public int[] findOrder(int n, int[][] pre) {
        ArrayList<ArrayList<Integer>>adj=new ArrayList<>();
        
        for(int i=0;i<n;i++){
            adj.add(new ArrayList<>());
        }
        for(int i=0;i<pre.length;i++){
            adj.get(pre[i][1]).add(pre[i][0]);
        }
        int[] indeg=new int[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<adj.get(i).size();j++){
                indeg[adj.get(i).get(j)]++;
            }
        }
        Queue<Integer>q=new LinkedList<>();
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.offer(i);
            }
        }
        ArrayList<Integer>ans=new ArrayList<>();
        while(!q.isEmpty()){
            int node=q.poll();
            ans.add(node);
            for(int i=0;i<adj.get(node).size();i++){
                indeg[adj.get(node).get(i)]--;
                if(indeg[adj.get(node).get(i)]==0){
                    q.offer(adj.get(node).get(i));
                }
            }
        }
        if(ans.size() != n) {
            return new int[0];
        }
        int n1=ans.size();
        int []arr=new int[n1];
        for(int i=0;i<n1;i++){
            arr[i]=ans.get(i);
        }
        return arr;
    }
}