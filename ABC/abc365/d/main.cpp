#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;

    cin >> N >> S;

    array<unsigned, 3> dp{};
    auto&& [rock, scissors, paper]{dp};

    for (auto x : dp) {
        cout << x << " ";
    }
    cout << endl;

    for (const char c : S) {
        dp = {max(scissors, paper), max(rock, paper), max(rock, scissors)};

        if (c == 'R') {
            scissors = 0;
            ++paper;
        } else if (c == 'S') {
            paper = 0;
            ++rock;
        } else if (c == 'P') {
            rock = 0;
            ++scissors;
        }
        for (auto x : dp) {
            cout << x << " ";
        }
        cout << endl;
    }

    // cout << ranges::max(dp) << endl;

    return 0;
}
