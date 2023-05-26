//
// Created by SeongHeon Sim on 2023/03/15.
// int 타입에 대해 학습
//
#include <bits/stdc++.h>

using namespace std;

int main() {
  // int 는 4 byte 의 정수 타입이다.
  // -2,147,483,648 ~ 2,147,483,647 의 범위
  // 최대 20억까지 표현할 수 있으며, 20억을 초과하는 경우 long long 을 사용해야 한다.

  int a = 10;
  cout << a << "\n";

  // 알고리즘 문제를 풀 때 대부분 int 의 최대값으로 20억이 아닌 987654321(1e9) 를 사용한다.
  // 그 이유는 INF + INF 나 INF * 2 등 여러 연산으로 인해 int 타입의 최대값을 넘지 않도록 오버플로를 방지하기 위해서다.
  const int INF = 987654321;
  cout << "INF : " << INF << "\n";
  const int INF_2 = 1e9; // 10 의 9승, 1000000000
  cout << "INF_2 : " << INF_2 << "\n";

  return 0;
}
