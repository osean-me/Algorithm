package java_algorithm;

import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

// https://www.acmicpc.net/problem/1213
public class Baekjoon_1213 {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static final String FAIL_RESULT = "I'm Sorry Hansoo";

    private static List<String> convert(Map<String, Integer> charMap) {
        List<String> chars = charMap.keySet().stream().sorted().collect(Collectors.toList());
        return chars.stream().map(c -> {
            int size = charMap.get(c);
            return IntStream.range(0, size / 2).mapToObj(i -> c).collect(Collectors.joining());
        }).collect(Collectors.toList());
    }

    private static String solution() throws IOException {
        String center = "";
        String input = br.readLine();
        Map<String, Integer> charMap = Arrays.stream(input.split(""))
                .collect(Collectors.toMap(Function.identity(), c -> 1, (before, after) -> {
                    before++;
                    return before;
                }));
        if (input.length() % 2 == 0) {
            boolean isNotEven = charMap.values().stream().anyMatch(size -> size % 2 != 0);
            if (isNotEven) return FAIL_RESULT;
        } else {
            long count = charMap.values().stream().filter(size -> size % 2 != 0).count();
            if (count > 1) return FAIL_RESULT;
            center = charMap.entrySet().stream().filter(entry -> entry.getValue() % 2 != 0).map(Map.Entry::getKey).findFirst().orElseThrow();
        }
        List<String> prefix = convert(charMap);
        List<String> suffix = prefix.stream().sorted(Comparator.reverseOrder()).collect(Collectors.toList());
        return String.join("", prefix) + center + String.join("", suffix);
    }

    public static void main(String[] args) throws IOException {
        String result = solution();
        bw.write(result);
        bw.newLine();
        bw.flush();
        bw.close();
        br.close();
    }
}
