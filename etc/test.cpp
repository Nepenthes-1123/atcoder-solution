#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    // TODO: Implement me!

    bool remain = true;
    string edit_s = s;

    while (remain) {
        remain = false;
        if (edit_s.size() <= 0) break;

        char pre = edit_s.at(0);
        vector<int> rem_indexs;

        for (int i = 1; i < (int)edit_s.size(); ++i) {
            if (pre == edit_s.at(i)) {
                remain = true;
                rem_indexs.push_back(i - 1);
                rem_indexs.push_back(i);
                break;
            }
            pre = edit_s.at(i);
        }

        for (int i = 0; i < (int)rem_indexs.size(); ++i) {
            edit_s.erase(edit_s.begin() + rem_indexs.at(i) - i);
        }
    }

    return edit_s;
}

int main() {
    string s;
    cin >> s;
    cout << solution(s) << endl;

    return 0;
}
