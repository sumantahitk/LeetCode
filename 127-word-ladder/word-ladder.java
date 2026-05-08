class Solution {

    class Pair {
        String word;
        int step;

        Pair(String word, int step) {
            this.word = word;
            this.step = step;
        }
    }

    public int ladderLength(String beginWord, String endWord, List<String> wordList) {

        Set<String> st = new HashSet<>(wordList);
        if (!st.contains(endWord)) return 0;

        Queue<Pair> q = new LinkedList<>();
        q.offer(new Pair(beginWord, 1));

        while (!q.isEmpty()) {
            Pair curr = q.poll();
            String word = curr.word;
            int step = curr.step;

            if (word.equals(endWord)) return step;

            char[] arr = word.toCharArray();

            for (int i = 0; i < arr.length; i++) {
                char original = arr[i];

                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == original) continue;  // optimization

                    arr[i] = c;
                    String newWord = new String(arr);

                    if (st.contains(newWord)) {
                        st.remove(newWord);
                        q.offer(new Pair(newWord, step + 1));
                    }
                }

                arr[i] = original;
            }
        }

        return 0;
    }
}