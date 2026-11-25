class Solution {
    public int firstUniqChar(String s) {
        Map<Character, Integer> mp = new LinkedHashMap<>();

        for(char c : s.toCharArray()) {
            mp.put(c, mp.getOrDefault(c, 0) + 1);
        }

        char ch = '#';

        for(Character key : mp.keySet()) {
            if(mp.get(key) == 1) {
                ch = key;
                break;
            }
        }

        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == ch) return i;
        }

        return -1;
    }
}