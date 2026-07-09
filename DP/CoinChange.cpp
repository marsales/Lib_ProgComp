// COIN CHANGE MÍNIMO
// Pode usar cada valor infinitas vezes
// Retorna menor quantidade de elementos para formar K, ou -1 se impossível
// Complexidade: O(nK)

int min_coins_unbounded(const vector<int>& coins, int K) {
    const int INF = 1e9;

    vector<int> dp(K + 1, INF);

    dp[0] = 0;

    for (int s = 1; s <= K; s++) {
        for (int x : coins) {
            if (s >= x) {
                dp[s] = min(dp[s], dp[s - x] + 1);
            }
        }
    }

    return dp[K] == INF ? -1 : dp[K];
}
