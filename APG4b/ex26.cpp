#include <bits/stdc++.h>
using namespace std;

string read_name() {
    string var_name, _;

    cin >> var_name >> _;

    return var_name;
}

int read_int(map<string, int> &var_int) {
    string value;
    cin >> value;
    if (isdigit(value.at(0))) {
        return stoi(value);
    } else {
        return var_int.at(value);
    }
}

int calc_int(map<string, int> &var_int) {
    int calc_val = 0, in_val = 0;
    string op = "";

    while (op != ";") {
        in_val = read_int(var_int);
        if (op == "") {
            calc_val = in_val;
        } else if (op == "+") {
            calc_val += in_val;
        } else if (op == "-") {
            calc_val -= in_val;
        }
        cin >> op;
    }

    return calc_val;
}

vector<int> read_vec_val(map<string, int> &var_int) {
    string symbol = "";

    vector<int> result;

    while (symbol != "]") {
        int val = read_int(var_int);

        result.push_back(val);

        cin >> symbol;
    }

    return result;
}

vector<int> read_vec(map<string, int> &var_int,
                     map<string, vector<int>> &var_vec) {
    string val;
    cin >> val;

    return val == "[" ? read_vec_val(var_int) : var_vec.at(val);
}

vector<int> calc_vec(map<string, int> &var_int,
                     map<string, vector<int>> &var_vec) {
    string symbol;
    vector<int> result;

    while (symbol != ";") {
        vector<int> vec = read_vec(var_int, var_vec);

        if (symbol == "") {
            result = vec;
        } else if (symbol == "+") {
            for (int i = 0; i < (int)result.size(); i++) {
                result.at(i) += vec.at(i);
            }
        } else if (symbol == "-") {
            for (int i = 0; i < (int)result.size(); i++) {
                result.at(i) -= vec.at(i);
            }
        }

        cin >> symbol;
    }

    return result;
}

// 問題文の形式でvec値を出力
void print_vec(vector<int> vec) {
    cout << "[ ";
    for (int i = 0; i < (int)vec.size(); i++) {
        cout << vec.at(i) << " ";
    }
    cout << "]" << endl;
}

int main() {
    int N;
    cin >> N;

    map<string, int> var_int;          // int変数を管理するmap
    map<string, vector<int>> var_vec;  // vector変数を管理するmap

    // 命令受け取り

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (s == "int") {
            string name = read_name();
            var_int[name] = calc_int(var_int);
        } else if (s == "vec") {
            string name = read_name();
            var_vec[name] = calc_vec(var_int, var_vec);
        } else if (s == "print_int") {
            cout << calc_int(var_int) << endl;
        } else if (s == "print_vec") {
            print_vec(calc_vec(var_int, var_vec));
        }
    }
}
