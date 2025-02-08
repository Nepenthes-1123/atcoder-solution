#include <bits/stdc++.h>
using namespace std;

#define MAX_INT numeric_limits<int>::max();

int main() {
    int n, m;
    cin >> n >> m;

    int min_a = MAX_INT;
    vector<int> customer(n), sushi(m), who_eat(m, -1);

    vector<pair<int, int>> customer_id(n);

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;

        if (a >= min_a) {
            a = MAX_INT;
        }
        customer_id.at(i).first = a;
        customer.at(i) = a;

        customer_id.at(i).second = i + 1;
        min_a = min(a, min_a);
    }

    for (int i = 0; i < m; ++i) {
        cin >> sushi.at(i);
    }

    sort(customer.begin(), customer.end());
    sort(customer_id.begin(), customer_id.end());

    for (int i = 0; i < n; ++i) {
        cout << customer_id.at(i).first << endl;
    }
    for (int si = 0; si < m; ++si) {
        int pos = lower_bound(customer.begin(), customer.end(), sushi.at(si)) -
                  customer.begin() - 1;
        cout << si << " " << pos << endl;
        cout << pos << " " << n << " " << customer.at(pos) << " "
             << sushi.at(si) << endl;
        if (0 <= pos && pos < n && customer.at(pos) <= sushi.at(si)) {
            cout << "eat" << endl;
            who_eat.at(si) = customer_id.at(pos).second;
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << who_eat.at(i) << endl;
    }

    return 0;
}
