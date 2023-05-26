//
// Created by SeongHeon Sim on 2023/03/29.
//
#include <bits/stdc++.h>

using namespace std;

int solve_1(string str) {
  int center = (str.length() / 2) + (str.length() % 2);

  // 중간의 전면과 후면을 비교
  for (int i = 0; i < center; i++) {
    // 문자열의 뒷 부분 인덱스
    int j = str.length() - i - 1;
    // 현재 인덱스와 대응하는 인덱스의 문자열이 서로 다르면 카운트++
    if (str[i] != str[j]) return 0;
  }
  return 1;
}

int solve_2(string str) {
  string tmp = str;
  reverse(tmp.begin(), tmp.end());
  if (str == tmp) return 1;
  return 0;
}

string str;
int main() {
  cin >> str;
  cout << solve_1(str) << "\n";
  cout << solve_2(str);
}
