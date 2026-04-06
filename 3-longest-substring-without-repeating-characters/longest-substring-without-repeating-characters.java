class Solution {
    public int lengthOfLongestSubstring(String s) {
        int l=0,h=0,n=s.length(),len=0;
        // int[] arr=new int[256];
        Map <Character,Integer> arr=new HashMap<>();
        
        while(h<n){
            char c=s.charAt(h);
            arr.put(c,arr.getOrDefault(c,0)+1);
            while(arr.get(c)>1){
                char ch=s.charAt(l);
                arr.put(ch,arr.get(ch)-1);
                l++;
            }
            len=Math.max(len,h-l+1);
            h++;

        }
        return len;
    }
}