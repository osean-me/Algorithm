//
// Created by SeongHeon Sim on 2023/03/16.
//
#include <bits/stdc++.h>

using namespace std;

int n;

// 피보나치
int fibonacci(int n) {
  if (n == 0 || n == 1) return n;
  return fibonacci(n - 2) + fibonacci(n - 1);
}

// 백준 2309
void baekjoon_2309() {
  // 입력된 난쟁이들의 키
  int array[9];

  for (int i = 0; i < 9; i++) {
    cin >> array[i];
  }

  // 난쟁이 정렬 (오름차순)
  for (int n = 0; n < 9; n++) {
    for (int m = n + 1; m < 9; m++) {
      if (array[m] <= array[n]) {
        int tmp = array[n];
        array[n] = array[m];
        array[m] = tmp;
      }
    }
  }

  // 난쟁이들의 키 합
  int totalLength = 0;
  for (int i: array) {
    totalLength += i;
  }

  // 제외할 난쟁이들
  int exclude[2] = {0, 0};

  // 찾기
  for (int n = 0; n < 9; n++) {
    for (int m = n + 1; m < 9; m++) {
      int result = totalLength - array[n] - array[m];
      if (result == 100) {
        exclude[0] = n;
        exclude[1] = m;
        break;
      }
    }
  }

  cout << "\n";
  // 인덱스
  int index = 0;
  // 결과
  int result[7];

  for (int i = 0; i < 9; i++) {
    if (i != exclude[0] && i != exclude[1]) {
      result[index] = array[i];
      index++;
    }
  }

  for (int i: result) {
    cout << i << "\n";
  }
}


int main() {
  // 피보나치 수열
  cin >> n;
  cout << fibonacci(n) << "\n";

  // 백준 2309
  baekjoon_2309();

  return 0;
}
