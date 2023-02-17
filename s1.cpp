#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int C;
    cin >> C;
    vector<int> ts(C);
    for (int i = 0; i < C; i++) {
        cin >> ts[i];
    }
    vector<int> bs(C);
    for (int i = 0; i < C; i++) {
        cin >> bs[i];
    }
    int ans = 0;
    for (int i = 0; i < C; i++)
        ans += 3 * ts[i] + 3 * bs[i];
    for (int i = 0; i < C - 1; i++) {
        if (ts[i] && ts[i + 1]) ans -= 2;
        if (bs[i] && bs[i + 1]) ans -= 2;
    }
    for (int i = 0; i < C; i += 2) {
        if (ts[i] && bs[i]) ans -= 2;
    }
    cout << ans << "\n";
}