#include <bits/stdc++.h>
using namespace std;

int main() {
    string t,u;
    cin >> t >> u;

    vector<int> q_index;

    for (int i = 0; i < (int)t.size(); ++i) {
        if(t.at(i)=='?') {
            q_index.push_back(i);
        }
    }

    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            for (int k = 0; k < 26; ++k) {
                for (int l = 0; l < 26; ++l) {
                    string s = t;
                    s.at(q_index[0]) = 'a' + i;
                    s.at(q_index[1]) = 'a' + j;
                    s.at(q_index[2]) = 'a' + k;
                    s.at(q_index[3]) = 'a' + l;

                    if (s.find(u) != string::npos) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
