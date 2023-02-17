#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int solve(vector<int>& hs, vector<vector<int>>& dp, int a, int b) {
    if (dp[a][b] != -1) return dp[a][b];
    if (a >= b) return dp[a][b] = 0;
    return dp[a][b] = abs(hs[a] - hs[b]) + solve(hs, dp, a + 1, b - 1);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> hs(N);
    for (int i = 0; i < N; i++)
        cin >> hs[i];

    vector<vector<int>> dp(N, vector<int>(N, -1));

    for (int i = 1; i <= N; i++) {
        int best = INT_MAX;

        for (int st = 0; st + i <= N; st++) {
            best = min(best, solve(hs, dp, st, st + i - 1));
        }

        cout << best;
        if (i != N) {
            cout << " ";
        }
    }
    cout << "\n";
}