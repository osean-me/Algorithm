#include <bits/stdc++.h>

using namespace std;

// 왜 input 을 복사가 아닌 참조를 하게 했을까?
// -> 메모리 낭비를 막기 위해서
vector<string> split(const string& input, string delimeter) {
    vector<string> result;
    auto start = 0;
    auto end = input.find(delimeter);
    while (end != string::npos) {
        result.push_back(input.substr(start, end - start));
        start = end + delimeter.size();
        end = input.find(delimeter, start);
    }
    result.push_back(input.substr(start));
    return result;
}

int main() {
    // cpp 에서는 별도로 split() 함수를 제공하지 않기 때문에 직접 구현해야 한다.
    string a = "a,b,c,d,e";
    vector<string> result = split(a, ",");
    for (const string& str : result) {
        cout << str << "\n";
    }
    return 0;
}