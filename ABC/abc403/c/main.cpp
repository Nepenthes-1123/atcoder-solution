#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    map<int, map<int, bool>> authority_map;

    map<int, bool> all_authority_users;

    for (int i = 0; i < n; ++i) {
        map<int, bool> authority;
        authority_map[i] = authority;
    }

    for (int i = 0; i < q; ++i) {
        int q_id;
        cin >> q_id;

        if(q_id == 1){
            int x, y;
            cin >> x >> y;

            authority_map.at(x - 1)[y - 1] = true;
        }
        else if(q_id == 2){
            int x;
            cin >> x;

            all_authority_users[x - 1] = true;
        }
        else if(q_id == 3){
            int x, y;
            cin >> x >> y;


            if(all_authority_users.count(x - 1)){
                cout << "Yes" << endl;
                continue;
            }

            if(!authority_map.at(x - 1).count(y - 1)){
                cout << "No" << endl;
                continue;
            }

            if(authority_map.at(x - 1).at(y - 1)){
                cout << "Yes" << endl;
            } else{
                cout << "No" << endl;
            }
        }


    }

    return 0;
}
