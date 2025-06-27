class Solution {
    public String longestSubsequenceRepeatedK(String s, int k) {
        String ans = "";
        Queue<String> q = new LinkedList<>();
        q.add("");

        while (!q.isEmpty()) {
            String str = q.poll();
            for (char ch = 'a'; ch <= 'z'; ch++) {
                String temp = str + ch;
                if (isKTimesRepeated(temp, s, k)) {
                    ans = temp;
                    q.add(temp);
                }
            }
        }
        return ans;
    }

    private boolean isKTimesRepeated(String sub, String s, int k) {
        int count = 0, i = 0;
        for (char c : s.toCharArray()) {
            if (i < sub.length() && c == sub.charAt(i)) {
                i++;
                if (i == sub.length()) {
                    count++;
                    i = 0;
                }
            }
        }
        return count >= k;
    }
}
