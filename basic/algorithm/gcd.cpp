//
// Created by SeongHeon Sim on 2023/03/21.
//

#include <bits/stdc++.h>
#include <vector>
#include <cmath>

using namespace std;

void print(vector<int> v) {
  cout << "\n";
  for (int i: v) {
    cout << i << "\n";
  }
}

/**
 * 재귀 함수를 사용해 두 수의 최대공약수 구하기
 * @param a
 * @param b
 * @return a, b 두 수의 최대공약수
 */
int gcd_recursion(int a, int b) {
  if (a == 0) return b;
  return gcd_recursion(b % a, a);
}

/**
 * n 의 약수 구하기
 * n / 2 만큼 반복문을 순회하여 나머지가 0 인 값을 vector 에 넣기
 * @return vector
 */
vector<int> getDivisor(int a) {
  vector<int> result;
  for (int i = 1; i <= a / 2; i++) {
    if (a % i == 0) {
      result.push_back(i);
    }
  }
  return result;
}

/**
 * n 의 약수 구하기
 * n 의 제곱근을 찾고 1 부터 제곱근까지 반복문을 통해 n 의 약수를 찾는다.
 * n 의 제곱근의 약수는 n 의 약수에 포함된다.
 * @param a
 * @return vector
 */
vector<int> getDivisor_2(int a) {
  vector<int> result;
  int root = sqrt(a);

  for (int i = 1; i <= root; i++) {
    if (a % i == 0) {
      result.push_back(i);
      if (a / i != i) result.push_back(a / i);
    }
  }
  sort(result.begin(), result.end());
  return result;
}

int main() {
  int result = gcd_recursion(5, 8);
  cout << result << "\n";

  vector<int> result_2 = getDivisor(24);
  print(result_2);

  vector<int> result_3 = getDivisor_2(100);
  print(result_3);

  return 0;
}
