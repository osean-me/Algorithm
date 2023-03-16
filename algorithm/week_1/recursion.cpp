//
// Created by SeongHeon Sim on 2023/03/16.
//
#include <bits/stdc++.h>

using namespace std;

int n;

int fibonacci(int n) {
  if (n == 0 || n == 1) return n;
  return fibonacci(n - 2) + fibonacci(n - 1);
}

int main() {
  cin >> n;
  cout << fibonacci(n) << "\n";
  return 0;
}
