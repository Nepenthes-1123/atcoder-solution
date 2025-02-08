#include <bits/stdc++.h>
using namespace std;

class dice {
   private:
    double k;

   public:
    map<int, double> prop;
    dice();
    dice(int);
    ~dice();

    void set_prop(vector<int> &);
};

dice::dice() {};
dice::dice(int K) { k = K; }

void dice::set_prop(vector<int> &A) {
    for (int a : A) {
        if (prop.count(a)) {
            prop.at(a) += 1 / k;
        } else {
            prop[a] = 1 / k;
        }
    }
}

dice::~dice() {}

int main() {
    int n;
    cin >> n;

    vector<dice> D(n);

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        D.at(i) = dice(k);

        vector<int> A(k);
        for (int j = 0; j < k; ++j) {
            cin >> A.at(j);
        }

        D.at(i).set_prop(A);
    }

    double max_p = 0;

    for (int i = 0; i < n; ++i) {
        dice d1 = D.at(i);
        for (int j = i + 1; j < n; ++j) {
            dice d2 = D.at(j);
            double now = 0;

            for (pair<int, double> p : d1.prop) {
                if (d2.prop.count(p.first)) {
                    now += p.second * d2.prop.at(p.first);
                }
            }

            max_p = max(max_p, now);
        }
    }

    cout << fixed << setprecision(15) << max_p << endl;

    return 0;
}
