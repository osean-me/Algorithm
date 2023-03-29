//
// Created by SeongHeon Sim on 2023/03/29.
//
#include <bits/stdc++.h>

using namespace std;

string str;
int cnt, result, center;
int main() {
  cin >> str;
  center = (str.length() / 2) + (str.length() % 2);

  // 중간의 전면과 후면을 비교
  for (int i = 0; i < center; i++) {
    // 같이 않은 경우가 발견되면 반복문 중단
    if (cnt > 0) continue;
    // 문자열의 뒷 부분 인덱스
    int j = str.length() - i - 1;
    // 현재 인덱스와 대응하는 인덱스의 문자열이 서로 다르면 카운트++
    if (str[i] != str[j]) cnt++;
  }
  // 카운트가 0개라면 펠린드롬
  if (cnt == 0) result = 1;
  cout << result << "\n";
}
