package java_algorithm;

import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Baekjoon_4659 {

    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private static final List<String> vowels = List.of("a", "e", "i", "o", "u");

    // 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
    private static boolean solution_1(String password) {
        return vowels.stream().anyMatch(password::contains);
    }

    // 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
    private static boolean solution_2(String password) {
        char[] chars = password.toCharArray();
        if (password.length() >= 3) {
            for (int start = 0; start < chars.length; start++) {
                String subString;
                int end = (start + 3);
                if (end < chars.length) subString = password.substring(start, end);
                else subString = password.substring(start);
                if (subString.length() == 3) {
                    List<String> subList = subString.chars().mapToObj(c -> String.valueOf((char) c)).collect(Collectors.toList());
                    boolean isVowel = subList.stream().allMatch(str -> vowels.stream().anyMatch(str::contains));
                    boolean isNotVowel = subList.stream().allMatch(str -> vowels.stream().noneMatch(str::contains));
                    if (isVowel || isNotVowel) return false;
                } else return true;
            }
        }
        return true;
    }

    // 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
    private static boolean solution_3(String password) {
        Deque<Character> stack = new ArrayDeque<>();
        char[] chars = password.toCharArray();
        stack.push(chars[0]);
        for (int i = 1; i < chars.length; i++) {
            Character peek = stack.peek();
            if (peek != null && (peek != 'e' && peek != 'o') && peek == chars[i]) return false;
            stack.push(chars[i]);
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        Map<String, Boolean> result = new LinkedHashMap<>();
        String input = br.readLine();
        while (!input.equals("end")) {
            boolean check1 = solution_1(input);
            boolean check2 = solution_2(input);
            boolean check3 = solution_3(input);
            result.put(input, check1 && check2 && check3);
            input = br.readLine();
        }
        br.close();
        for (Map.Entry<String, Boolean> entry : result.entrySet()) {
            if (entry.getValue()) bw.write(String.format("<%s> is acceptable.", entry.getKey()));
            else bw.write(String.format("<%s> is not acceptable.", entry.getKey()));
            bw.newLine();
        }
        bw.flush();
        bw.close();
    }
}
