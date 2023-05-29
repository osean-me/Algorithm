package java_algorithm;

public class Codility_02 {

    public int[][] createNode(int N, int[] A, int[] B) {
        int[][] node = new int[N][N];
        for (int i = 0; i < A.length; i++) {
            int y = A[i] - 1;
            int x = B[i] - 1;
            node[y][x] = 1;
            node[x][y] = 1;
        }
        return node;
    }

    public boolean isPossible(int[][] node) {
        int N = node.length;
        for (int y = 0; y < N - 1; y++) {
            int x = y + 1;
            if (y + 1 < N && node[y][x] != 1) return false;
        }
        return true;
    }

    public boolean solution(int N, int[] A, int[] B) {
        int[][] node = createNode(N, A, B);
        return isPossible(node);
    }

    public static void main(String[] args) {
        Codility_02 solution = new Codility_02();
        boolean result = solution.solution(6, new int[]{2, 4, 5, 3}, new int[]{3, 5, 6, 4});
        System.out.println(result);
    }
}
