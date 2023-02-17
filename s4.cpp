#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll djik(vector<vector<pair<int, ll>>>& es, int a, int b) {
    set<pair<int, int>> q;
    vector<ll> dp(es.size(), 1e17);
    dp[a] = 0;
    q.insert({0, a});
    while (q.size()) {
        auto [d, v] = *q.begin();
        q.erase(q.begin());
        for (auto [u, c] : es[v]) {
            if (dp[v] + c < dp[u]) {
                if (q.find({dp[u], u}) != q.end()) q.erase(q.find({dp[u], u}));
                dp[u] = dp[v] + c;
                q.insert({dp[u], u});
            }
        }
    }
    return dp[b];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    map<pair<int, int>, vector<pair<ll, ll>>> rs;
    ll ans = 0;
    for (int i = 0; i < M; i++) {
        int u, v;
        ll l, c;
        cin >> u >> v >> l >> c;
        u--, v--;
        rs[{u, v}].push_back({l, c});
    }

    multimap<pair<ll, ll>, pair<ll, ll>> esq;

    for (auto& [k, v] : rs) {
        sort(v.begin(), v.end());
        esq.insert({v[0], k});
    }

    vector<vector<pair<int, ll>>> es(N);

    for (auto [x, y] : esq) {
        auto [l, c] = x;
        auto [u, v] = y;
        ll exis = djik(es, u, v);
        if (exis > l) {
            es[u].push_back({v, l});
            es[v].push_back({u, l});
            ans += c;
        }
    }

    cout << ans << "\n";
}