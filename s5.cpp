#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> solve(ll N) {
    if (N == 1) {
        return {0, 1};
    }
    if (N == 2) {
        return {0, 2};
    }
    if (N % 3 == 0) {
        auto v = solve(N / 3);
        ll len = v.size();
        for (ll i = len - 1; i >= 0; i--) {
            v.push_back(N - v[i]);
        }
        return v;
    }
    return {};
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;

    for (ll a : solve(N)) {
        cout << a << "\n";
    }
}