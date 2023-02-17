#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, R, C;
    cin >> N >> M >> R >> C;

    vector<string> ans(N, string(M, 'b'));

    if (R == 0 && C == 0) {
        for (int i = 0; i < N - 1; i++) {
            ans[i][0] = 'a';
        }
        for (int j = 1; j < M; j++) {
            ans[N - 1][j] = 'a';
        }

        for (auto& s : ans)
            cout << s << "\n";
        return 0;
    }

    if (C == 0) {
        if (R == N) {
            for (int i = 0; i < M; i++) {
                ans[0][i] = 'a';
            }

            for (auto& s : ans)
                cout << s << "\n";
            return 0;
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < M; j++) {
                ans[i][j] = 'a';
            }
        }
        for (int i = R; i < N; i++) {
            ans[i][0] = 'c';
        }
        for (auto& s : ans)
            cout << s << "\n";
        return 0;
    }

    if (R == 0) {
        if (C == M) {
            for (int i = 0; i < N; i++) {
                ans[i][0] = 'a';
            }
            for (auto& s : ans)
                cout << s << "\n";
            return 0;
        }
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < N; j++) {
                ans[j][i] = 'a';
            }
        }
        for (int i = C; i < M; i++) {
            ans[0][i] = 'c';
        }
        for (auto& s : ans)
            cout << s << "\n";
        return 0;
    }

    if (R == N) {
        // cout << "---\n";
        if (C % 2 == 1 && M % 2 == 0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        for (int i = 0; i < M; i++) {
            ans[0][i] = 'a';
        }
        for (int i = 0; i < C / 2; i++) {
            for (int j = 1; j < N; j++) {
                ans[j][i] = 'a';
                ans[j][M - 1 - i] = 'a';
            }
        }
        if (C % 2) {
            for (int j = 1; j < N; j++) {
                ans[j][M / 2] = 'a';
            }
        }
        for (auto& s : ans)
            cout << s << "\n";
        return 0;
    }

    if (C == M) {
        if (R % 2 == 1 && N % 2 == 0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        for (int i = 0; i < N; i++) {
            ans[i][0] = 'a';
        }
        for (int i = 0; i < R / 2; i++) {
            for (int j = 1; j < M; j++) {
                ans[i][j] = 'a';
                ans[N - 1 - i][j] = 'a';
            }
        }
        if (R % 2) {
            for (int j = 1; j < M; j++) {
                ans[N / 2][j] = 'a';
            }
        }
        for (auto& s : ans)
            cout << s << "\n";
        return 0;
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < M; j++) {
            ans[i][j] = 'a';
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < C; j++) {
            ans[i][j] = 'a';
        }
    }
    int rr = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M / 2; j++) {
            if (ans[i][j] != ans[i][M - 1 - j]) goto NOT;
        }
        rr++;

    NOT:;
    }
    if (rr != R) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    int cc = 0;
    for (int j = 0; j < M; j++) {
        for (int i = 0; i < N / 2; i++) {
            if (ans[i][j] != ans[N - 1 - i][j]) goto NOT1;
        }
        cc++;
    NOT1:;
    }
    if (cc != C) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (auto& s : ans)
        cout << s << "\n";
}