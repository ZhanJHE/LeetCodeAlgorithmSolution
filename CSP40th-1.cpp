
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// 计算集合 S 的 f(S) 值
int calculate_f(const vector<int>& a, const unordered_set<int>& S) {
    int result = 0;
    for (int x : S) {
        result ^= a[x];
    }
    return result;
}

// 判断 f(S_i) == f(T_i) 时 S_i 是否等于 T_i
bool is_equal(const unordered_set<int>& S, const unordered_set<int>& T) {
    return S == T;
}

int main() {
    int n, m;
    cin >> n >> m;

    // 读取数列 a
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 读取集合 S 和 T
    vector<unordered_set<int>> S(m);
    vector<unordered_set<int>> T(m);

    for (int i = 0; i < m; ++i) {
        int size;
        cin >> size;
        for (int j = 0; j < size; ++j) {
            int x;
            cin >> x;
            S[i].insert(x - 1); // 调整为 0-indexed
        }
    }

    for (int i = 0; i < m; ++i) {
        int size;
        cin >> size;
        for (int j = 0; j < size; ++j) {
            int x;
            cin >> x;
            T[i].insert(x - 1); // 调整为 0-indexed
        }
    }

    // 判断每一对 S_i 和 T_i
    for (int i = 0; i < m; ++i) {
        int f_S = calculate_f(a, S[i]);
        int f_T = calculate_f(a, T[i]);

        if (f_S == f_T) {
            cout << (is_equal(S[i], T[i]) ? "Yes" : "No") << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
