//
// Created by SeongHeon Sim on 2023/03/21.
//

#include <bits/stdc++.h>

using namespace std;

int gcd_recursion(int a, int b) {
  if (a == 0) return b;
  return gcd_recursion(b % a, a);
}

int main() {
  int result = gcd_recursion(5, 5);
  cout << result << "\n";
  return 0;
}
