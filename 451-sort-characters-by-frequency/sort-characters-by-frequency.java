class Solution {
    public String frequencySort(String s) {
        Map<Character,Integer>mp=new HashMap<>();
        for(int i=0;i<s.length();i++){
            char ch=s.charAt(i);
            mp.put(ch,mp.getOrDefault(ch,0)+1);
        }
        List<Character>list=new ArrayList<>(mp.keySet());
        Collections.sort(list,(a,b)->mp.get(b)-mp.get(a));

        StringBuilder sb=new StringBuilder();
        for(Character key:list){
            int n=mp.get(key);
            while(n!=0){
                sb.append(key);
                n--;
            }
        }

        return sb.toString();
    }
}