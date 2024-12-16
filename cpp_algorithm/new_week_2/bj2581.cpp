#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> getSieve(int start, int end) {
    vector<bool> isPrime(end + 1, true);
    isPrime[0] = isPrime[1] = false;

    // 2부터 end까지 소수를 찾는다.
    for (int i = 2; i <= end; i++) {  // i의 배수를 찾아 제거
        if (isPrime[i]) {  // i가 소수인 경우, i의 배수는 소수가 아니다.
            for (int j = i * i; j <= end; j += i) isPrime[j] = false;
        }
    }

    vector<int> sieve;
    for (int i = start; i <= end; i++) {
        if (isPrime[i]) sieve.push_back(i);
    }

    return sieve;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vector<int> sieve = getSieve(n, m);
    vector<int> psum(sieve.size() + 1, 0);

    if (!sieve.size()) {
        cout << -1;
        return 0;
    }

    for (int i = 1; i <= sieve.size(); i++) {
        psum[i] = (psum[i - 1] + sieve[i - 1]);
    }

    cout << *(psum.end() - 1) << "\n" << *sieve.begin();
}