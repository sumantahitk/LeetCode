class Solution {
    public int firstUniqChar(String s) {
        int[] freq = new int[26];

        // Step 1: Calculate frequency
        for (char ch : s.toCharArray()) {
            freq[ch - 'a']++;
        }

        // Step 2: Find first non-repeating character
        for (int i = 0; i < s.length(); i++) {
            if (freq[s.charAt(i) - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
}