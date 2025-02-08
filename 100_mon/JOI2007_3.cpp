#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> X(N), Y(N);

    for (int i = 0; i < N; ++i) {
        cin >> X.at(i) >> Y.at(i);
    }

    int64_t area = 0;

    int x1, y1, x2, y2;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int dx = X.at(i) - X.at(j);
            int dy = Y.at(i) - Y.at(j);
            bool tf = false;

            // 正方形セット1
            x1 = X.at(i) - dy;
            y1 = Y.at(i) + dx;
            x2 = X.at(j) - dy;
            y2 = Y.at(j) + dx;
            bool tf1 = false, tf2 = false;
            for (int chck = 0; chck < N; ++chck) {
                if (X.at(chck) == x1 && Y.at(chck) == y1) tf1 = true;
                if (X.at(chck) == x2 && Y.at(chck) == y2) tf2 = true;
            }
            if (tf1 && tf2) tf = true;

            // 正方形セット2
            x1 = X.at(i) + dy;
            y1 = Y.at(i) - dx;
            x2 = X.at(j) + dy;
            y2 = Y.at(j) - dx;
            tf1 = false;
            tf2 = false;
            for (int chck = 0; chck < N; ++chck) {
                if (X.at(chck) == x1 && Y.at(chck) == y1) tf1 = true;
                if (X.at(chck) == x2 && Y.at(chck) == y2) tf2 = true;
            }
            if (tf1 && tf2) tf = true;

            if (tf) {
                area = max(area, (int64_t)(dx * dx + dy * dy));
            }
        }
    }

    cout << area << endl;
}
