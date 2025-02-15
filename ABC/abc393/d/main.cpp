#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;

    cin >> n >> s;

    vector<int> subscripts;

    for (int i = 0; i < (int)s.size(); ++i) {
        if (s.at(i) == '1') subscripts.push_back(i);
    }

    int pivot_sub = (int)subscripts.size() / 2;
    int pivot = subscripts.at(pivot_sub);
    int series_cnt = 0;

    int now = pivot;
    int dist = 0;
    for (int i = pivot_sub + 1; i < (int)subscripts.size(); ++i) {
        if (subscripts.at(i) - now == 1) {
            series_cnt += dist;
            ++dist;
        } else {
            break;
        }
        now = subscripts.at(i);
    }

    now = pivot;
    dist = 0;
    for (int i = pivot_sub - 1; i >= 0; --i) {
        if (now - subscripts.at(i) == 1) {
            series_cnt += dist;
            ++dist;
        } else {
            break;
        }
        now = subscripts.at(i);
    }

    for (int i = 0; i < (int)subscripts.size(); ++i) {
        subscripts.at(i) = abs(subscripts.at(i) - pivot);
        if (subscripts.at(i) != 0) --subscripts.at(i);
    }

    int64_t count = 0;

    for (int i = 0; i < (int)subscripts.size(); ++i) {
        count += subscripts.at(i);
    }

    if ((int)subscripts.size() > 3) {
        count -= (int)subscripts.size() - 3;
    }

    cout << count - series_cnt << endl;

    return 0;
}
