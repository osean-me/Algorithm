//
// Created by SeongHeon Sim on 2023/03/15.
//
#include <bits/stdc++.h>

using namespace std;

int main() {

  // atoi() > 문자열인지 아닌지 확인하는 함수
  string s = "안녕하세요";

  // 입력받은 문자열이 문자라면 0 을 반환
  cout << "s : " << atoi(s.c_str()) << "\n";

  string s2 = "10";

  // 입력받은 숫자라면 해당 숫자를 반환
  cout << "s2 : " << atoi(s2.c_str()) << "\n";

  return 0;
}
