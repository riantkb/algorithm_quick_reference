/*
 * ABC025C_alphabeta
 * submission : https://beta.atcoder.jp/contests/abc025/submissions/2627929
 */

#include<bits/stdc++.h>
using namespace std;
const int INF = 1000000007;

int b[6], c[6];
int cnt;

inline int calc_chokudai_score(int a) {
    int ret = 0;
    for (int i = 0; i < 9; ++i) {
        if (i < 6 && (a >> i * 2 & 3) == (a >> (i + 3) * 2 & 3)) ret += b[i];
        if (i % 3 < 2 && (a >> i * 2 & 3) == (a >> (i + 1) * 2 & 3)) ret += c[i - i / 3];
    }
    return ret;
}

int dfs(int dep, int a, int low, int high) {
    ++cnt;
    if (dep == 9) return -calc_chokudai_score(a);

    int ret = -INF;
    for (int i = 0; i < 9; ++i) {
        if (!((a >> i * 2) & 3)) {
            ret = max(ret, -dfs(dep + 1, a | ((dep & 1) + 1) << i * 2, -high, -low));
            low = max(low, ret);
            if (low >= high) break;
        }
    }
    return ret;
}

int main() {
    int all = 0;
    for (int i = 0; i < 6; ++i) {
        cin >> b[i];
        all += b[i];
    }
    for (int i = 0; i < 6; ++i) {
        cin >> c[i];
        all += c[i];
    }
    cnt = 0;
    int chokudai = dfs(0, 0, -INF, INF);
    // cout << "cnt : " << cnt << "\n";
    cout << chokudai << "\n" << all - chokudai << "\n";
    return 0;
}
