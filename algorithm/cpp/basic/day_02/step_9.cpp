//
// Created by SeongHeon Sim on 2023/03/15.
// C++ 에서의 논리 타입에 대해 학습
//
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // C++ 에서는 0 을 제외한 나머지 값은 모두 true 이다.
  // 즉, 0 = false / 나머지 = true
  int a = -1;
  cout << bool(a) << "\n";

  a = 0;
  cout << bool(a) << "\n";

  a = 1;
  cout << bool(a) << "\n";

  return 0;
}
