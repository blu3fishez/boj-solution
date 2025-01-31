import java.util.Comparator;
import java.util.PriorityQueue;

class Solution {
    PriorityQueue<Integer> pq = new PriorityQueue<>();
    public int solution(int[] scoville, int K) {
        int answer = 0;
        
        for (int i=0; i<scoville.length; ++i) {
            pq.add(scoville[i]);
        }
        
        while(!pq.isEmpty()) {
            int first = pq.poll();
            
            if (pq.isEmpty()) {
                if (first >= K) return answer;
                return -1;
            }

            int second = pq.poll();

            if (first >= K && second >= K) return answer;

            pq.add(first + second * 2);
            answer++;
        }

        return -1;
    }
}