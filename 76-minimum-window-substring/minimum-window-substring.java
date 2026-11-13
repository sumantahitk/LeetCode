class Solution {
    public String minWindow(String s, String t) {
        int []arr=new int[128];
        int k=t.length();
        for(char ch:t.toCharArray()){
            arr[ch]++;
        }
        int l=0,h=0,n=s.length(),st=0,end=0,mn=Integer.MAX_VALUE;
        while(h<n){
            char ch=s.charAt(h);
            arr[ch]--;
            if(arr[ch]>=0){
                k--;
            }
            while(k==0){
                int len=h-l+1;
                if(len<mn){
                    mn=len;
                    st=l;
                    end=h;
                }
                arr[s.charAt(l)]++;
                if(arr[s.charAt(l)]>0){
                    k++;
                }
                l++;
            }
            h++;
        }
        if(mn == Integer.MAX_VALUE) return "";
        return s.substring(st,end+1);
    }
}