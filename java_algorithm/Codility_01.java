package java_algorithm;

public class Codility_01 {

    // 십진 표기를 반대로 표시하라
    // 뒤집은 값의 첫 자리가 0 인 정수는 출력하면 안된다.
    // N = 54321 > 12345
    // N = 10011 > 11001
    // N = 1 > 1
    public void solution(int N) {
        int enable_print = N % 10;
        StringBuilder result = new StringBuilder();
        while (N > 0) {
            if (enable_print == 0 && N % 10 != 0) {
                enable_print = 1;
            } else if (enable_print == 1) {
                result.append(N % 10);
            }
            N = N / 10;
        }
        if (!result.toString().startsWith("0")) System.out.print(result);
    }

    public static void main(String[] args) {
        Codility_01 solution = new Codility_01();
        solution.solution(54321);
    }
}
