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
        // cout << "q " << d << " " << v << endl;
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
        // ans += c;
    }

    multimap<pair<ll, ll>, pair<ll, ll>> esq;

    for (auto& [k, v] : rs) {
        // cout << (k.first + 1) << " " << (k.second + 1) << "\n";
        sort(v.begin(), v.end());
        // for (int i = 1; i < (int)v.size(); i++) {
        // ans -= v[i].second;
        // }
        esq.insert({v[0], k});
    }

    vector<vector<pair<int, ll>>> es(N);

    for (auto [x, y] : esq) {
        // auto [u, v, c] = y;
        auto [l, c] = x;
        auto [u, v] = y;
        // cout << (u + 1) << " " << (v + 1) << " " << c << "\n";
        ll exis = djik(es, u, v);
        // cout << "djik " << (u + 1) << " " << (v + 1) << " " << exis << endl;
        if (exis > l) {
            es[u].push_back({v, l});
            es[v].push_back({u, l});
            ans += c;
            // cout << "use \n";
        }
    }

    cout << ans << "\n";
}