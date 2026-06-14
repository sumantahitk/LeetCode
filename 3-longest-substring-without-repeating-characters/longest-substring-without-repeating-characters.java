class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character,Integer>mp=new HashMap<>();
        int i=0,n=s.length(),j=0,ans=0,mx=0;
        while(i<n){
            char ch=s.charAt(i);
            mp.put(ch,mp.getOrDefault(ch,0)+1);
            while(mp.get(ch)>1){
              char left = s.charAt(j);
                mp.put(left, mp.get(left) - 1);
                if (mp.get(left) == 0) {
                    mp.remove(left);
                }
                j++;
            }
            mx=Math.max(mx,i-j+1);
            i++;
        }
        return mx;
    }
}