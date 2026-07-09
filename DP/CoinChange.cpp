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



// Conta formas de formar K usando moedas infinitas
// Ordem importa
// Complexidade: O(nK)

long long count_ways_unbounded_ordered(const vector<int>& coins, int K) {
    vector<long long> dp(K + 1, 0);

    dp[0] = 1;

    for (int s = 1; s <= K; s++) {
        for (int x : coins) {
            if (s >= x) {
                dp[s] += dp[s - x];
            }
        }
    }

    return dp[K];
}




// Conta formas de formar K usando moedas infinitas
// Ordem não importa
// Complexidade: O(nK)

long long count_ways_unbounded_orderless(const vector<int>& coins, int K) {
    vector<long long> dp(K + 1, 0);

    dp[0] = 1;

    for (int x : coins) {
        for (int s = x; s <= K; s++) {
            dp[s] += dp[s - x];
        }
    }

    return dp[K];
}
