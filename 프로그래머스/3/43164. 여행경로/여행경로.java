import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.PriorityQueue;

class Solution {

    HashMap<String, PriorityQueue<String>> map = new HashMap<>();
    List<String> journey = new ArrayList<>();
    boolean found = false;

    public String[] solution(String[][] tickets) {
        for (int i = 0; i < tickets.length; ++i) {
            String from = tickets[i][0];
            String to = tickets[i][1];

            PriorityQueue<String> value = map.getOrDefault(from, new PriorityQueue<>());
            value.add(to);

            map.put(from, value);
        }

        search("ICN");

        Collections.reverse(journey);

        return journey.toArray(new String[journey.size()]);
    }

    public void search(String currentPlace) {

        PriorityQueue<String> pq = map.get(currentPlace);

        while (pq != null && !pq.isEmpty()) {

            String place = pq.poll();

            search(place);
        }

        journey.add(currentPlace);
    }
}