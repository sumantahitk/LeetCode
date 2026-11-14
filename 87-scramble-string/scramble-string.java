
import java.util.*;

class Solution {
    HashMap<String, Boolean> dp = new HashMap<>();

    boolean find(String s1, String s2) {
        if (s1.equals(s2)) return true;
        if (s1.length() != s2.length()) return false;
        if (s1.length() <= 1) return false;

        String key = s1 + "#" + s2;

        if (dp.containsKey(key))
            return dp.get(key);

        int n = s1.length();

        for (int i = 1; i < n; i++) {

            // Swapped
            if (find(s1.substring(0, i), s2.substring(n-i)) &&
                find(s1.substring(i), s2.substring(0, n-i))) {
                dp.put(key, true);
                return true;
            }

            // Not swapped
            if (find(s1.substring(0, i), s2.substring(0, i)) &&
                find(s1.substring(i), s2.substring(i))) {
                dp.put(key, true);
                return true;
            }
        }

        dp.put(key, false);
        return false;
    }

    public boolean isScramble(String s1, String s2) {
        dp.clear();

        if (s1.length() != s2.length()) return false;

        return find(s1, s2);
    }
}
