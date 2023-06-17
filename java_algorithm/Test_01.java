package java_algorithm;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Test_01 {
    public int solution(int[] estimates, int k) {
        List<Integer> sumList = new ArrayList<>();
        for (int i = 0; i <= estimates.length - k; i++) {
            int sum = 0;
            for (int j = i; j < i + k; j++) {
                sum += estimates[j];
            }
            sumList.add(sum);
        }
        return Collections.max(sumList);
    }

    public static void main(String[] args) {
        Test_01 test = new Test_01();
        int[] estimates = {10, 1, 10, 1, 1, 4, 3, 10};
        int k = 6;
        int result = test.solution(estimates, k);
        System.out.println(result);
    }
}
