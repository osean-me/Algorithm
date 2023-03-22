//
// Created by SeongHeon Sim on 2023/03/22.
//
#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

int lcm(int a, int b) {
  return (a * b) / gcd(a, b);
}

int main() {
  int result = lcm(82, 92);
  cout << "lcm(82, 92) : " << result << "\n";
  return 0;
}
