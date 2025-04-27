#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    unordered_map<int, int> count_nums;              // 数字が何回出現したか
    unordered_map<int, pair<int, int>> count_diffs;  // 差分dに何回関わったか

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        count_diffs[a.at(i)] = make_pair(0, 0);

        if (count_nums.count(a.at(i))) {
            count_nums.at(a.at(i))++;
        } else {
            count_nums[a.at(i)] = 1;
        }
    }

    for (auto nums : count_nums) {
        for (int i = 0; i < n; ++i) {
            if (abs(nums.first - a.at(i)) == d) {
                if (nums.first > a.at(i)) {
                    count_diffs.at(nums.first).first++;
                } else {
                    count_diffs.at(nums.first).second++;
                }
            }
        }
    }

    for (auto nums : count_diffs) {
        cout << nums.second.first << " " << nums.first << " "
             << nums.second.second << " " << count_nums.at(nums.first) << endl;
    }

    cout << endl;

    vector<pair<int, int>>
        sort_diffs;  // 差分dに関わった数字。secondが数字そのもの
    for (auto nums : count_diffs) {
        sort_diffs.push_back(
            make_pair((nums.second.first + nums.second.second) *
                          count_nums.at(nums.first),
                      nums.first));
    }

    sort(sort_diffs.rbegin(), sort_diffs.rend());

    for (auto nums : count_diffs) {
        cout << nums.second.first << " " << nums.first << " "
             << nums.second.second << endl;
    }

    int ans = 0;

    for (auto nums : sort_diffs) {
        if (count_diffs.count(nums.second) != 0)
            ans += (count_diffs.at(nums.second).first +
                    count_diffs.at(nums.second).second) *
                   count_nums.at(nums.second);

        if (count_diffs.count(nums.second - d)) {
            count_diffs.at(nums.second - d).first -=
                count_diffs.at(nums.second).second / count_nums.at(nums.second);
        }
        if (count_diffs.count(nums.second + d)) {
            count_diffs.at(nums.second + d).second -=
                count_diffs.at(nums.second).first / count_nums.at(nums.second);
        }
    }

    cout << ans << endl;

    return 0;
}
