// KNAPSACK
/*
Problema: Dada uma mochila com capacidade W e n itens, cada um com
peso w[i] e valor v[i], qual o maior valor que dá pra colocar na mochila
sem passar do peso?

dp[w] -> melhor valor com capacidade w
*/

int n, W;
vector<int> w, v;

vector<int> dp(W+1, 0);

for (int i = 0; i < n; ++i) {
    for (int k = W - w[i]; k >= 0; --k) {
        dp[k + w[i]] = max( dp[k + w[i]] , dp[k] + v[i] );
    }
}

cout << dp[W] << endl;
