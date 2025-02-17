import java.util.HashMap;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        HashMap<String, Integer> m = new HashMap<>();

        for (String c : completion) {
            m.put(c, m.getOrDefault(c, 0) + 1);
        }

        for (String p : participant) {
            var count = m.getOrDefault(p, 0);
            if (count == 0) {
                answer = p;
            } else {
                m.put(p, count - 1);
            }
        }

        return answer;
    }
}