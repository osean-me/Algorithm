#include <bits/stdc++.h>

using namespace std;

string convert(bitset<32> b) {
    string s = b.to_string();
    auto first_one = s.find("1");

    if (first_one != string::npos) {
        return s.substr(first_one);
    }

    return "0";
}

int main() {
    int num;
    cin >> num;

    string num_str = convert(bitset<32>(num));
    string ret_str = convert(bitset<32>((1 << num_str.size()) - 1));
    cout << num_str << '\n' << ret_str;
}