//
// Created by SeongHeon Sim on 2023/03/21.
//
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int n = 5;
int r = 3;
int size = 0;

void print(vector<int> v) {
  for (int value: v) {
    cout << value << " ";
  }
  cout << "\n";
}

void comb(int i, vector<int> v) {
  if (v.size() == r) {
    print(v);
    size++;
    return;
  }

  for (int j = i + 1; j < n; j++) {
    v.push_back(j);
    comb(j, v);
    v.pop_back();
  }
}

int main() {
  vector<int> v;

  // 재귀 함수로 Combination 구현
  comb(-1, v);
  cout << "result : " << size << "\n\n";

  // 사이즈 초기화
  size = 0;

  // 중첩 for 문으로 Combination 구현
  for (int i = 0; i < n; i++) {
    v.push_back(i);
    for (int j = i + 1; j < n; j++) {
      v.push_back(j);
      for (int k = j + 1; k < n; k++) {
        v.push_back(k);
        print(v);
        v.pop_back();
        size++;
      }
      v.pop_back();
    }
    v.pop_back();
  }
  cout << "result : " << size << "\n\n";

  return 0;
}
/*
  0 1 2
  0 1 3
  0 1 4
  0 2 3
  0 2 4
  0 3 4
  1 2 3
  1 2 4
  1 3 4
  2 3 4
  result : 10
 */
