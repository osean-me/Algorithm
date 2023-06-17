package java_algorithm;

import java.util.HashMap;
import java.util.Map;

public class Test_02 {
    private int getScore(int[] cards1, int[] cards2) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < cards1.length; i++) {
            map.putIfAbsent(cards1[i], 0);
            map.computeIfPresent(cards1[i], (k, v) -> v + 1);
            map.putIfAbsent(cards2[i], 0);
            map.computeIfPresent(cards2[i], (k, v) -> v + 1);
        }

        return map.values().stream().mapToInt(count -> count * (count + 1) / 2).sum();
    }

    public int solution(int[] cards1, int[] cards2) {
        int count = 0;
        int score = getScore(cards1, cards2);
        return count;
    }

    public static void main(String[] args) {
        Test_02 test = new Test_02();
        int[] card1 = {1, 1, 2, 2, 3, 3, 4};
        int[] card2 = {1, 1, 2, 2, 2, 3, 3};
        int result = test.solution(card1, card2);
        System.out.println("result = " + result);
    }
}
