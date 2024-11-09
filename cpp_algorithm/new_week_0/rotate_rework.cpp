#include <bits/stdc++.h>

using namespace std;

void print(vector<int> &input) {
    for (int value : input) cout << value << " ";
    cout << "\n";
    return;
}

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

template <typename Iterator>
Iterator rotate_copy(Iterator start, Iterator middle, Iterator end) {
    if (start == middle || end == middle) return middle;

    int n = end - start;
    int k = middle - start;
    int gcdValue = gcd(n, k);

    for (int i = 0; i < gcdValue; ++i) {
        auto temp = *start;
        auto current = start;

        while (true) {
            auto next = current + k;

            if (next >= end) next -= n;
            if (next == start) break;

            *current = *next;
            current = next;
        }

        *current = temp;
        ++start;
    }

    return start + (end - middle);
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6};
    rotate_copy(v.begin(), v.begin() + 2, v.end());
    print(v);
    rotate_copy(v.rbegin(), v.rbegin() + 2, v.rend());
    print(v);
    return 0;
}