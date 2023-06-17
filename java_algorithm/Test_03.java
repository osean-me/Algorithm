package java_algorithm;

import java.util.*;
import java.util.stream.Collectors;

public class Test_03 {
    private final char[] targets = {'(', ')', '[', ']', '{', '}'};

    private char getTarget(char[] chars) {
        Map<Character, Integer> countMap = new HashMap<>();
        for (char c : chars) {
            countMap.putIfAbsent(c, 0);
            countMap.computeIfPresent(c, (k, v) -> v + 1);
        }
        char target = targets[0];
        for (int i = 0; i < targets.length - 1; i += 2) {
            Integer start = countMap.get(targets[i]);
            Integer end = countMap.get(targets[i + 1]);
            if (start != null && end != null && (start + end) % 2 != 0) {
                int min = Math.min(start, end);
                if (start == min) target = targets[i];
                if (end == min) target = targets[i + 1];
            }
        }
        return target;
    }

    private boolean isClose(char peek, char next) {
        for (int i = 0; i < targets.length - 1; i += 2) {
            if (peek == targets[i] && next == targets[i + 1]) return true;
        }
        return false;
    }

    public int solution(String s) {
        char target = getTarget(s.toCharArray());
        int count = 0;
        for (int i = 0; i <= s.length(); i++) {
            List<Character> chars = s.chars().mapToObj(c -> (char) c).collect(Collectors.toList());
            chars.add(i, target);
            Deque<Character> stack = new ArrayDeque<>();
            stack.push(chars.get(0));
            for (int j = 1; j < chars.size(); j++) {
                char next = chars.get(j);
                if (stack.peek() != null) {
                    char peek = stack.peek();
                    if (isClose(peek, next)) {
                        stack.pop();
                    } else {
                        stack.push(next);
                    }
                } else {
                    stack.push(next);
                }
            }

            if (stack.size() == 0) count++;
        }
        return count;
    }

    public static void main(String[] args) {
        Test_03 test = new Test_03();
        int result = test.solution("(()()()");
    }
}
