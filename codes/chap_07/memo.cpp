/*
 * ABC025C_memo
 * submission : https://beta.atcoder.jp/contests/abc025/submissions/2627950
 */

#include<bits/stdc++.h>
using namespace std;
const int INF = 1000000007;

int b[6], c[6];
int memo[3 << 16];

int cnt;

inline int calc_chokudai_score(int a) {
    int ret = 0;
    for (int i = 0; i < 9; ++i) {
        if (i < 6 && (a >> i * 2 & 3) == (a >> (i + 3) * 2 & 3)) ret += b[i];
        if (i % 3 < 2 && (a >> i * 2 & 3) == (a >> (i + 1) * 2 & 3)) ret += c[i - i / 3];
    }
    return ret;
}

int dfs(int dep, int a) {
    ++cnt;
    if (memo[a] != -INF) return memo[a];
    if (dep == 9) return memo[a] = -calc_chokudai_score(a);

    int ret = -INF;
    for (int i = 0; i < 9; ++i) {
        if (!((a >> i * 2) & 3)) {
            ret = max(ret, -dfs(dep + 1, a | ((dep & 1) + 1) << i * 2));
        }
    }
    return memo[a] = ret;
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
    for (int i = 0; i < (3 << 16); ++i) memo[i] = -INF;
    cnt = 0;
    int chokudai = dfs(0, 0);
    // cout << "cnt : " << cnt << "\n";
    cout << chokudai << "\n" << all - chokudai << "\n";
    return 0;
}
