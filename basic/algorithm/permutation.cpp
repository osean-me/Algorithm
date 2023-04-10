//
// Created by SeongHeon Sim on 2023/03/17.
//
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void printV(vector<int> &v) {
  for (int i: v) cout << i << " ";
  cout << "\n";
}

int a[3] = {1, 2, 3};
vector<int> v;

void permutation() {
  // 벡터에 데이터 추가
  for (int i: a) v.push_back(i);

  // 오름차순으로 순열 출력
  do {
    printV(v);
  } while (next_permutation(v.begin(), v.end()));

  cout << "------" << "\n";

  // 벡터 초기화
  v.clear();

  // 벡터에 데이터 추가
  for (int i = 2; i >= 0; i--) v.push_back(a[i]);

  // 내림차순으로 순열 출력
  do {
    printV(v);
  } while (prev_permutation(
      v.begin(), // vector 의 첫 번째 인덱스에 위치한 값 (배열에서는 사용할 수 없는 함수)
      v.end() // vector 의 마지막 인덱스의 다음의 주소값 (배열에서는 사용할 수 없는 함수)
  ));

  // next_permutation() 사용 시, 정렬된 배열을 사용하는 것이 중요하다.
  // 정렬되어 있지 않은 경우, 모든 경우의 수가 나오지 않는다.
  // 그 이유는 next_permutation() 함수가 배열의 그 다음 순열을 만들어내는 함수이기 때문이다.
  cout << "\n";
}

void recursive_permutation(int n, int r, int depth) {
  if (r == depth) {
    for (int i = 0; i < r; i++) {
      cout << a[i] << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = depth; i < n; i++) {
    swap(a[i], a[depth]);
    recursive_permutation(n, r, depth + 1);
    swap(a[i], a[depth]);
  }
}

int main() {
  // 오름차순 / 내림차순 순열 출력
  permutation();
  recursive_permutation(3, 3, 0);
  return 0;
}
/*
  1 2 3
  1 3 2
  2 1 3
  2 3 1
  3 1 2
  3 2 1
  ------
  3 2 1
  3 1 2
  2 3 1
  2 1 3
  1 3 2
  1 2 3
 */

