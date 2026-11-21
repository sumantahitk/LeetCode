class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int n1=g.length,n2=s.length;
        int i=0,j=0,cnt=0;
        while(i<n1 && j<n2){
            if(s[j]>=g[i]){
                cnt++;
                i++;
                j++;
            }else{
                j++;
            }
        }
        return cnt;
    }
}