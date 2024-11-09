#include <bits/stdc++.h>

using namespace std;

void print(vector<string> &input) {
    for (string value : input) cout << value << "\n";
    return;
}

vector<string> split(string input, string delimeter) {
    vector<string> result;
    int start = 0;
    int end = input.find(delimeter);
    while (end != string::npos) {
        result.push_back(input.substr(start, end - start));
        start = end + delimeter.size();
        end = input.find(delimeter, start);
    }
    result.push_back(input.substr(start));
    return result;
}

int main() {
    string input = "hi, nice to meet you.";
    string delimeter = ",";
    auto result = split(input, delimeter);
    print(result);
    return 0;
}