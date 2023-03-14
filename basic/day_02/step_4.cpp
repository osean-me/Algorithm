//
// Created by SeongHeon Sim on 2023/03/15.
// 입력과 출력
//
#include <bits/stdc++.h>

using namespace std;

int a;
double b;
char c;
long long lf;
int aa, bb;
string s;

int main() {
    scanf("%d %lf %c %ld", &a, &b, &c, &lf);
    printf("%d\n", a);
    printf("%lf\n", b);
    printf("%c\n", c);
    printf("%lf\n", lf);

    scanf("%d.%d\n", &aa, &bb);
    printf("%d.%d\n", aa, bb);

    getline(cin, s);
    cout << s << "\n";

    return 0;
}
