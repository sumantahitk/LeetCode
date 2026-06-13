class Solution {
    public int[][] merge(int[][] in) {
        Arrays.sort(in,(a,b)->a[0]-b[0]);
        List<List<Integer>>list=new ArrayList<>();
        list.add(new ArrayList<>(Arrays.asList(in[0][0],in[0][1])));
        
        for(int i=1;i<in.length;i++){
            int u=in[i][0];
            int v=in[i][1];
            List<Integer> last=list.get(list.size()-1);
            if(last.get(1)>=u){
                last.set(1,Math.max(v,last.get(1)));
            }else{
                list.add(new ArrayList<>(Arrays.asList(u,v)));
            }
        }
        int n=list.size();
        int[][] ans=new int[n][2];
        for(int i=0;i<n;i++){
            ans[i][0]=list.get(i).get(0);
            ans[i][1]=list.get(i).get(1);
        }
        return ans;
    }
}